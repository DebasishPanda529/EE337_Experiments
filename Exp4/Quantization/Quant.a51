ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL TAKE_INP
CALL QUANT_ENC
CALL LED_DISP
HERE: SJMP HERE
ORG 130H
// *****************
DELAY:
// ADD YOUR CODE HERE
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

TAKE_INP:
// ADD YOUR CODE HERE
MOV R2, #0FH     //FOR LED
MOV R1, #60H     //POINTER FOR STORING
MOV R3, #04H     //FOR LOOP

input:  MOV A, R2          
		ADD A, #10H        
		MOV P1, A         
		ACALL delay_10s
		MOV R2, A         
        MOV A, P1         
		ANL A, #0FH       
		SWAP A                 
		//FIRST PART OF INPUT 
		MOV B, A           
		MOV A, R2          
		ADD A, #10H        
		MOV P1, A         
		ACALL delay_10s
		MOV R2, A         
		MOV A, P1         
		ANL A, #0FH      
		//SECOND PART OF INPUT
		ADD A, B
		//BOTH INPUTS COMBINED
		MOV @R1, A 
		INC R1      
		DJNZ R3, input
		RET
	  
delay_10s:
PUSH 00H
MOV R0, #40
h5: ACALL DELAY
    DJNZ R0, h5
POP 00H
RET

QUANT_ENC:
// ADD YOUR CODE HERE
MOV R0, #60H
MOV R1, #70H
MOV R2, #04H

L1: MOV A, @R0
    MOV B, A
    SUBB A, #0AH
    MOV A, B
    JNC L2
    MOV @R1, #05H
    SJMP stop

L2: SUBB A, #14H
    MOV A, B
	JNC L3
	MOV @R1, #0FH
	SJMP stop
	   
L3: SUBB A, #1EH
    MOV A, B
    JNC L4
	MOV @R1, #19H
	SJMP stop
	   
L4: MOV @R1, #23H
    MOV A, B
	SJMP stop

stop: INC R0
      INC R1
      DEC R2
      CJNE R2, #00H, L1 	  
      RET
	
LED_DISP:
// ADD YOUR CODE HERE
MOV R1, #70H
MOV R2, #04H

D1: MOV A, @R1
    CJNE A, #05H, D2
	MOV P1, #10H
    SJMP loop
	
D2: CJNE A, #0FH, D3
    MOV P1, #20H
	SJMP loop
	
D3: CJNE A, #19H, D4
    MOV P1, #40H 
	SJMP loop
	
D4: MOV P1, #80H
    SJMP loop
	
loop: ACALL delay_5s
      INC R1
      DEC R2
	  CJNE R2, #00H, D1
	  ACALL LED_DISP

delay_5s: 
PUSH 00H
MOV R0, #20
h4: ACALL DELAY
    DJNZ R0, h4
POP 00H
RET

END