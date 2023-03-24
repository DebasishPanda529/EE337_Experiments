#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]=" START PROGRAM  ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="  FIRST INPUT   ";						//Display msg on 1st line of lcd
code unsigned char display_msg3[]="   NEXT INPUT   ";						//Display msg on 1st line of lcd
code unsigned char display_msg4[]="   SORTING...   ";						//Display msg on 1st line of lcd
code unsigned char display_msg5[]="    SORTING     ";           //Display msg on 1st line of lcd
code unsigned char display_msg6[]="   COMPLETED    ";					  //Display msg on 2nd line of lcd
code unsigned char display_msg7[]="  NUMBER TO BE  ";						//Display msg on 1st line of lcd
code unsigned char display_msg8[]="    SEARCHED    ";						//Display msg on 2nd line of lcd
code unsigned char display_msg9[]="  THE INDEX IS  ";						//Display msg on 1st line of lcd
code unsigned char display_msg10[]="     NUMBER     ";					//Display msg on 1st line of lcd
code unsigned char display_msg11[]="   NOT FOUND    ";					//Display msg on 2nd line of lcd

unsigned int time=5000;                                         //Delay of 5 sec
unsigned int i=0;  
unsigned int j=0;
unsigned int k=0;
unsigned int min=0;

unsigned char input[]={0,0,0,0,0};
unsigned char search=0;

void main()
{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	P1=0x0F;
	lcd_write_string(display_msg1);
	msdelay(time);
	
	lcd_cmd(0x80);													//Move cursor to first line
	lcd_write_string(display_msg2);
	msdelay(time);                          //Take first input
  P1=P1<<4;                               //Swap the nibbles of P1
	P1=P1 & 0xF0;
	input[0]=P1;                            //Store the first element and start the LEDs
  msdelay(time);
	P1=P1 & 0x0F;
	msdelay(time/5);                        //Switch off the LEDs
	P1=P1 | 0x0F;
	
	for(i=1; i<4; i++){
	lcd_cmd(0x80);                          //Move cursor to first line
	lcd_write_string(display_msg3);
	msdelay(time);                          //Take next input
	P1=P1<<4;
  P1=P1 & 0xF0;
	input[i]=P1;                            //Store the element and start the LEDs
	msdelay(time);
	P1=P1 & 0x0F;                           
	msdelay(time/5);                        //Switch off the LEDs
	P1=P1 | 0x0F;
	}
	
	lcd_cmd(0x80);                          //Move cursor to first line   
	lcd_write_string(display_msg3);
	msdelay(time);
	lcd_cmd(0x80);
	lcd_write_string(display_msg4); 
	P1=P1<<4;
	P1=P1 & 0xF0;
	input[4]=P1;                            //Store the element and start the LEDs
	msdelay(time);
	P1=P1 & 0x0F;
	lcd_cmd(0x80);
	lcd_write_string(display_msg5);
	lcd_cmd(0xC0);
	lcd_write_string(display_msg6);
	msdelay(time/5);                        //All inputs taken, now show the sorted outputs
	
	//SORTING ALGORITHM
	for(i=0; i<5; i++){
	  for(j=0; j<5-i; j++){
				if(input[j+1]<input[j]){
					min=input[j+1];
					input[j+1]=input[j];
					input[j]=min;
				} 
		}
	}
	for(i=0; i<5; i++){
		P1=input[i];
	  msdelay(time);
		P1=0x0F;
		msdelay(time/5);
	}
  
	P1=0x0F;
	msdelay(time/5);
	P1=0xFF;
	lcd_cmd(0x80);
	lcd_write_string(display_msg7);
	lcd_cmd(0xC0);
	lcd_write_string(display_msg8);
	msdelay(time);                          //Take input for the number to be searched
	P1=P1 & 0x0F;
	search=P1;
	search=search<<4;
	
  lcd_cmd(0x01);                          //Clear the LEDs and LCD
	msdelay(time/5);  
	
	//SEARCH ALGORITHM
	for(i=0; i<5; i++){
	if(input[i]==search){
	  k=1;
	  i=i<<4;
	  P1=i;
		lcd_cmd(0x80);
	  lcd_write_string(display_msg9);
	  break;                                //Number found
	 }
	else continue;
	}
	if(k==0){
	P1=0xFF;
	lcd_cmd(0x80);
	lcd_write_string(display_msg10);
	lcd_cmd(0xC0);
	lcd_write_string(display_msg11);        //Not found
	}

	while(1);
		
}