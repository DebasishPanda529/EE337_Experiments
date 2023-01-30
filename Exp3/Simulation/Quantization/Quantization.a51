ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL QUANT
HERE: SJMP HERE
ORG 130H
// *****************
QUANT:
// ADD YOUR CODE HERE
MOV R0, #60H
MOV R1, #70H
MOV R2, #08H

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
END