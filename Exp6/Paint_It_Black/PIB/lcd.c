#include <at89c5131.h>
#include "lcd.h"

//code unsigned char display_msg1[]="      Pt-51     ";						//Display msg on 1st line of lcd
//code unsigned char display_msg2[]="   IIT Bombay   ";						//Display msg on 1st line of lcd

code unsigned char msg1[]=  "I see a red door";						
code unsigned char msg2_1[]=" And I want it  ";
code unsigned char msg2_2[]=" painted black/ ";
code unsigned char msg3_1[]="   No colors    ";
code unsigned char msg3_2[]="    anymore/    ";
code unsigned char msg4_1[]="I want them to  ";
code unsigned char msg4_2[]="  turn black/   ";
code unsigned char msg5_1[]="I see the girls ";
code unsigned char msg5_2[]="    walk by/    ";
code unsigned char msg6_1[]="Dressed in their";
code unsigned char msg6_2[]="summer clothes/ ";
code unsigned char msg7_1[]="I have to turn  ";
code unsigned char msg7_2[]="    my head/    ";
code unsigned char msg8_1[]="   Until my     ";
code unsigned char msg8_2[]=" darkness goes/ ";
code unsigned char msg9_1[]="  I see a line  ";
code unsigned char msg9_2[]="    of cars/    ";
code unsigned char msg10_1[]="And they're all ";
code unsigned char msg10_2[]=" painted black/ ";
code unsigned char msg11_1[]="  With flowers  ";
code unsigned char msg11_2[]="  and my love/  ";
code unsigned char msg12_1[]=" Both never to  ";
code unsigned char msg12_2[]="  come back/    ";
code unsigned char msg13_1[]="I've seen people";
code unsigned char msg13_2[]="turn their heads";
code unsigned char msg14_1[]="   And quickly  ";
code unsigned char msg14_2[]="   look away/   ";
code unsigned char msg15_1[]=" Like a newborn ";
code unsigned char msg15_2[]="     baby/      ";
code unsigned char msg16_1[]="It just happens ";
code unsigned char msg16_2[]="   everyday/    ";
code unsigned char msg17_1[]=" I look inside  ";
code unsigned char msg17_2[]="     myself/    ";
code unsigned char msg18_1[]="And see my heart";
code unsigned char msg18_2[]="    is black/   ";
code unsigned char msg19_1[]="    I see my    ";
code unsigned char msg19_2[]="    red door/   ";
code unsigned char msg20_1[]=" I must have it ";
code unsigned char msg20_2[]=" painted black/ ";
code unsigned char msg21_1[]="Maybe then, I'll";
code unsigned char msg21_2[]="   fade away/   ";
code unsigned char msg22_1[]="And not have to ";
code unsigned char msg22_2[]="face the facts/ ";
code unsigned char msg23_1[]=" It's not easy  ";
code unsigned char msg23_2[]="   facing up/   ";
code unsigned char msg24_1[]="When your whole ";
code unsigned char msg24_2[]="world is black/ ";
code unsigned char msg25_1[]="No more will my ";
code unsigned char msg25_2[]="   green sea/   ";
code unsigned char msg26_1[]="   Go turn a    ";
code unsigned char msg26_2[]="  deeper blue/  ";
code unsigned char msg27_1[]="I could not fore";
code unsigned char msg27_2[]="-see this thing/";
code unsigned char msg28_1[]="  Happening to  ";
code unsigned char msg28_2[]="      you/      ";
code unsigned char msg29_1[]="    If I look   ";
code unsigned char msg29_2[]="  hard enough/  ";
code unsigned char msg30_1[]="    Into the    ";
code unsigned char msg30_2[]="  setting sun/  ";
code unsigned char msg31_1[]="  My love will  ";
code unsigned char msg31_2[]=" laugh with me/ ";
code unsigned char msg32_1[]="   Before the   ";
code unsigned char msg32_2[]=" morning comes/ ";
code unsigned char msg33_1[]="     I see a    ";
code unsigned char msg33_2[]="    red door/   ";
//code unsigned char msg34_1[]="  And I want it ";
//code unsigned char msg34_2[]=" painted black/ ";
//code unsigned char msg35_1[]="    No colors   ";
//code unsigned char msg35_2[]="     anymore/   ";
//code unsigned char msg36_1[]=" I want them to ";
//code unsigned char msg36_2[]="   turn black/  ";
//code unsigned char msg37_1[]="    I see the   ";
//code unsigned char msg37_2[]=" girls walk by/ ";
//code unsigned char msg38_1[]="Dressed in their";
//code unsigned char msg38_2[]="summer clothes/ ";
//code unsigned char msg39_1[]=" I have to turn ";
//code unsigned char msg39_2[]="     my head/   ";
//code unsigned char msg40_1[]="    Until my    ";
//code unsigned char msg40_2[]=" darkness goes/ ";
//code unsigned char msg41_1[]="   I wanna see  ";
//code unsigned char msg41_2[]="   it painted/  ";
//code unsigned char msg42[]="  Painted black/  ";
//code unsigned char msg43[]="  Black as night/ ";
//code unsigned char msg44[]="  Black as coal/  ";
//code unsigned char msg45_1[]="  I wanna see   ";
//code unsigned char msg45_2[]="    the sun/    ";
//code unsigned char msg46_1[]="   Blotted out  ";
//code unsigned char msg46_2[]="  from the sky/ ";
//code unsigned char msg47_1[]=" I wanna see it ";
//code unsigned char msg47_2[]="    painted,    ";
//code unsigned char msg47_3[]="    painted,    ";
//code unsigned char msg47_4[]="    painted/    ";
//code unsigned char msg48_1[]=" Painted black, ";
//code unsigned char msg48_2[]="     yeah/      ";

unsigned int t=3000;

void main()
{
	lcd_init();
	lcd_cmd(0x80);													
  msdelay(4);
	lcd_write_string(msg1);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg2_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg2_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg3_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg3_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg4_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg4_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg5_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg5_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg6_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg6_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg7_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg7_2);
	msdelay(t);	
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg8_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg8_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg9_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg9_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg10_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg10_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg11_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg11_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg12_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg12_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg13_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg13_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg14_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg14_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg15_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg15_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg16_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg16_2);
	msdelay(t);
  lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg17_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg17_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg18_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg18_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg19_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg19_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg20_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg20_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg21_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg21_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg22_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg22_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg23_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg23_2);
	msdelay(t);
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(msg24_1);
	lcd_cmd(0xC0);													
	msdelay(4);
	lcd_write_string(msg24_2);
	msdelay(t);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg25_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg25_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg26_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg26_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg27_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg27_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg28_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg28_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg29_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg29_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg30_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg30_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg31_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg31_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg32_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg32_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg33_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg33_2);
//	msdelay(5000);
//	lcd_cmd(0x80);													
//	msdelay(4);
//	lcd_write_string(msg34_1);
//	lcd_cmd(0xC0);													
//	msdelay(4);
//	lcd_write_string(msg34_2);
//	msdelay(5000);
	
	while(1);
		
}