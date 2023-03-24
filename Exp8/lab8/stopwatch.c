#include <at89c5131.h>
#include "lcd.h"

sbit DIP=P1^0;
sbit LED1=P3^4;

unsigned int a=0;         //Lower nibble (TL0)
unsigned int b=0;         //Upper nibble (TH0)
unsigned int count=0;     //Total count after concatenation
unsigned int mins=0;      //Minutes count
unsigned int secs=0;      //Seconds count
unsigned int mins_1;
unsigned int mins_2;
unsigned int secs_1;
unsigned int secs_2;

unsigned char mins_lcd1='0';
unsigned char mins_lcd2='0';
unsigned char secs_lcd1='0';
unsigned char secs_lcd2='0';

code unsigned char display_msg1[]="  STOPWATCH ON  ";
code unsigned char display_msg2[]="  STOPWATCH OFF ";

void timer0_isr () interrupt 1
{
   LED1 = ~LED1;
   TH0 = 0xFF;
   TL0 = 0xC4;
   TF0 = 0;
   //Reload values for TH1 and TL1. Start timer 1.
   
}

//void AFG()
//{
//	//TMOD = 0x15;
//  TMOD = 0x10; //mode 1 timer 1
//  TH1 = 0x7D;  //Values for Timer 1 TH1
//  TL1 = 0xCA;  //Values for Timer 1 TL1
//  ET1 = 1;
//  EA = 1;      //activate global interrupts
//  TR1 = 1;     //start timer 1   
//}

void main(void)
{
	//AFG();

	TMOD = 0x05;
	TH0 = 0xFF;
	TL0 = 0xC4;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	
	 lcd_init();
	 while(1)
	 {
		 while(DIP == 1)              //External control through DIP switch
		 {
			 TR0 = 1;
				
			 a = TL0;
			 b = TH0;
			 count = 256*b + a;
			 count = count/60;         //Every 60 cycles make up 1 s
			 mins = count/60;
			 secs = count-(mins*60);
			 mins_1 = mins/10;
			 mins_2 = mins-(10*mins_1);
			 secs_1 = secs/10;
			 secs_2 = secs-(10*secs_1);
			 mins_lcd1 = mins_1 + 48;
			 mins_lcd2 = mins_2 + 48;
			 secs_lcd1 = secs_1 + 48;
			 secs_lcd2 = secs_2 + 48;   //Converting int to char for LCD display
				
			 lcd_cmd(0x80);
			 lcd_write_string(display_msg1);
			 lcd_cmd(0xC5);
			 lcd_write_char(mins_lcd1);
			 lcd_write_char(mins_lcd2);
			 lcd_write_char(':');
			 lcd_write_char(secs_lcd1);
			 lcd_write_char(secs_lcd2);
		 }
	 
		 while(DIP == 0)
		 {
			 TR0 = 0;
			 TL0 = 0;
			 TH0 = 0;                   //To start the stopwatch again from 0 once it has been turned OFF and then turned ON
			 
			 lcd_cmd(0x80);
			 lcd_write_string(display_msg2);		 
			 lcd_cmd(0xC5);
			 lcd_write_char(mins_lcd1);
			 lcd_write_char(mins_lcd2);
			 lcd_write_char(':');
			 lcd_write_char(secs_lcd1);
			 lcd_write_char(secs_lcd2);
		 }
   }
	 
}

