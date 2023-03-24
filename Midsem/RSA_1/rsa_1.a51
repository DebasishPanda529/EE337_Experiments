ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL INPUT
CALL LOOP
CALL LED_DISP
HERE: SJMP HERE
ORG 130H
//********************
DELAY:
PUSH 00H
MOV R0, #250
h3: ACALL delay_1ms
    DJNZ R0, h3
POP 00H
RET
	
delay_1ms: PUSH 00H
		   MOV R0, #4
		   h2: ACALL delay_250us
		   DJNZ R0, h2
		   POP 00H
		   RET
	
delay_250us: PUSH 00H
	         MOV R0, #244
	         h1: DJNZ R0, h1
	         POP 00H
	         RET
//********************	
INPUT:
MOV 70H, #0D8H   //x
MOV 71H, #0ADH   //e
MOV 72H, #05H
MOV R0, #01H     //i
MOV R1, #01H     //d
RET

LOOP: MOV A, 70H
      MOV B, R0
      MUL AB
	  MOV R2, B   //MSB FOR (x*i)
	  MOV R3, A   //LSB FOR (x*i)
      ;ACALL MODULO 
      ACALL LED_DISP 	  
   
MODULO: MOV A, R1    //d
        MOV B, 71H   //e
	    MUL AB
		MOV R4, A    //R4 HAS LSB OF (d*e)
		MOV A, R3    //A HAS LSB OF (x*i)
		SUBB A, R4   //LSB
		MOV R5, A    //R5 STORES VALUE OF LSB AFTER SUBB
		MOV R4, B    //R4 HAS MSB OF (d*e)
		MOV A, R2    //A HAS MSB OF (x*i)
	    SUBB A, R4   //MSB
		MOV R4, A    //R4 STORES VALUE OF MSB AFTER SUBB
	    JNC check
        INC R0
		ACALL LOOP
	 
check: CJNE R5, #00H, next      //IF LSB != 01H, THEN GO TO next
       CJNE R4, #01H, next
	   MOV 72H, R1
	   ACALL LED_DISP

next: INC R1
      CLR C
	  SJMP MODULO
	  
LED_DISP: 
MOV B, 72H
ANL B, #10H
MOV P1, B
ACALL delay_5s
MOV P1, #00H
ACALL delay_1s
MOV B, 72H
ANL B, #01H
MOV P1, B
ACALL delay_5s
MOV P1, #00H
ACALL delay_1s
ACALL LED_DISP

delay_5s: 
PUSH 00H
MOV R0, #20
h4: ACALL DELAY
    DJNZ R0, h4
POP 00H
RET

delay_1s:
PUSH 00H
MOV R0, #4
h5: ACALL DELAY
    DJNZ R0, h5
POP 00H
RET

END