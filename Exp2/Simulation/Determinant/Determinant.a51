ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL DET
HERE: SJMP HERE
ORG 130H
// *****************
DET:
// ADD YOUR CODE HERE
MOV A, 61H    
MOV B, 62H   
MUL AB
MOV 61H, A   
MOV 62H, B    
MOV A, 60H    
MOV B, 63H    
MUL AB 
SUBB A, 61H
MOV 71H, A
MOV A, B
SUBB A, 62H
MOV 70H, A
RET
END