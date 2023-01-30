ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL SORT
HERE: SJMP HERE
ORG 130H
// *****************
SORT:
// ADD YOUR CODE HERE
MOV R3, #07H  

stop:MOV 70H, 60H
     MOV 71H, 61H
     MOV 72H, 62H
     MOV 73H, 63H
     MOV 74H, 64H
     MOV 75H, 65H
     MOV 76H, 66H
     MOV 77H, 67H
     SJMP stop
	   
L2:MOV R1, #60H     
   MOV R2, 03H   

L1:DEC R2
   CLR C
   MOV A, @R1       
   INC R1
   MOV R6, A        
   SUBB A, @R1
   JC no_swap
   MOV A, R6
   XCH A, @R1
   DEC R1
   MOV @R1, A
   INC R1
	   
no_swap:CJNE R2, #00H, L1
	    DEC R3                
	    CJNE R3, #00H, L2  

RET
END