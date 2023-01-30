ORG 0H
LJMP MAIN
ORG 100H
MAIN:
MOV R1, #61H
CALL MODADD
CALL MODSUB
HERE: SJMP HERE
ORG 130H
// *****************
MODADD:
// ADD YOUR CODE HERE
MOV A, 70H
MOV B, 71H
ADD A, B
MOV B, R1
DIV AB
MOV 72H, B
RET
MODSUB:
// ADD YOUR CODE HERE
MOV A, 70H
MOV B, 71H
SUBB A, B    
JNC carry_check_0
JC carry_check_1
carry_check_0: MOV B, R1
               DIV AB
               MOV 73H, B
               RET
carry_check_1: MOV R0, A  
               MOV A, #01H 
               SUBB A, R0    
               MOV B, R1     
               DIV AB        
               MOV A, R1     
               MOV R0, B    
               SUBB A, R0
               MOV 73H, A
               RET
END