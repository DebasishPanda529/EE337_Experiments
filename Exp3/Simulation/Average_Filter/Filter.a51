ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL FILT
HERE: SJMP HERE
ORG 130H
// *****************
FILT:
// ADD YOUR CODE HERE
MOV R0, #60H
MOV R1, #70H
MOV R2, #08H

BODY: MOV A, @R0     //x[n]
      DEC R0               
	  ADD A, @R0
	  MOV R3, A      //R3 = x[n] + x[n-1]
	  DEC R0
	  MOV A, @R0     //x[n-2]
	  DEC R0
	  ADD A, @R0
	  ADD A, R3
	  MOV B, #04H
	  DIV AB
	  MOV @R1, A
	  MOV A, R0
	  ADD A, #03H
	  MOV R0, A
	  SJMP STOP
	  
STOP: INC R0
      INC R1
	  DEC R2
	  CJNE R2, #00H, BODY

RET
END
