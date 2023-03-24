#include <at89c5131.h>
#include "lcd.h"

code unsigned char pw[]="15A8*D6#";
unsigned char input_pw[]="15A8*D6#"; 
code unsigned char display_msg1[]="Enter Password: ";
code unsigned char display_msg2[]="Correct Password";
code unsigned char display_msg3[]=" Access Granted ";
code unsigned char display_msg4[]=" Wrong Password ";
code unsigned char display_msg5[]=" Access Denied  ";
unsigned char display_msg6[]="                ";        //To append and display the input character
unsigned char input_char='0';                           //To store the input at each iteration?

unsigned int i=0;
unsigned int a=0;
unsigned int time=5000;
unsigned int debounce=20;
unsigned int col=0;           //To store row number
unsigned int row=0;           //To store column number
unsigned char table[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};  //To store the lookup table

unsigned int key_read(void)
{
	lcd_init();
	lcd_cmd(0x80);													
	P1=0x0F;
	lcd_write_string(display_msg1);         //Display initial message on the LCD
	
	//Column scanning and debouncing algorithm
	P3_7=0;
	P3_6=0;
	P3_5=0;
	P3_4=0;               //Ground all rows
	P3=0x0F;              //Read all columns
	while(P3!=0x0F){
	P3=0x0F;
	}
	P3=0x0F;              //Read all columns
	while(P3==0x0F){
	P3=0x0F;
	}
  msdelay(debounce);
	P3=0x0F;              //Read all columns
	while(P3==0x0F){
		P3=0x0F;            //Read all columns
		while(P3!=0x0F){
		P3=0x0F;
		}
		P3=0x0F;            //Read all columns
		while(P3==0x0F){
		P3=0x0F;
		}
		msdelay(debounce);
		P3=0x0F;
		}	
	
  //Assign column value
	if(P3_3==0)      col=0;
	else if(P3_2==0) col=1;
	else if(P3_1==0) col=2;
	else             col=3;
	
  //Row scanning algorithm		
  P3=0xEF;
	if(P3!=0xEF) row=0;
	else{P3=0xDF;
		   if(P3!=0xDF) row=1;
		   else{P3=0xAF;
            if(P3!=0xAF) row=2;
            else{P3=0x7F;
							   if(P3!=0x7F) row=3;
							   else P3=0xEF;
						    }
			     }
			}
	
	//Determine the key pressed
	if(row==0 && col==0)       input_char='1';
	else if(row==1 && col==0)  input_char='4';
	else if(row==2 && col==0)  input_char='7';
	else if(row==3 && col==0)  input_char='*';
	else if(row==0 && col==1)  input_char='2';
	else if(row==1 && col==1)  input_char='5';
	else if(row==2 && col==1)  input_char='8';
	else if(row==3 && col==1)  input_char='0';
	else if(row==0 && col==2)  input_char='3';
	else if(row==1 && col==2)  input_char='6'; 
	else if(row==2 && col==2)  input_char='9';
	else if(row==3 && col==2)  input_char='#';
	else if(row==0 && col==3)  input_char='A';
	else if(row==1 && col==3)  input_char='B';
	else if(row==2 && col==3)  input_char='C';
	else                       input_char='D';
	
	//You can also use a 2-D array to assign the keys
	
	return input_char;  
}	

void main(){ 
	
  lcd_init();
	
	for(i=0; i<8; i++){
    input_pw[i]=key_read();
    display_msg6[6]=input_pw[i];
    lcd_cmd(0xC0);
    lcd_write_string(display_msg6);		         //Iterations to take the input
	}
	
	for(i=0; i<8; i++){
    if(input_pw[i]!=pw[i]) {a=1; break;}
		else a=0;                   
	}                                            //Checking for the equality of the strings
	
	if(a==1){
		lcd_init();
		lcd_cmd(0x80);
		lcd_write_string(display_msg4);
		lcd_cmd(0xC0);
		lcd_write_string(display_msg5);
	  }                                          //Wrong Password
  else{
	  lcd_init();
	  lcd_cmd(0x80);
	  lcd_write_string(display_msg2);
	  lcd_cmd(0xC0);
    lcd_write_string(display_msg3);
	  }                                           //Correct Password

}