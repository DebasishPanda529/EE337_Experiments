ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL INPUT
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
MOV 70H, #0F7H
MOV P1, #0FH
MOV B, 70H
MOV A, P1
MOV A, 71H      //c
MOV 72H, #04H   //d

MULTIPLY:
MOV B, A
MUL AB      //B HAS MSB, A HAS LSB


END
