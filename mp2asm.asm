section .data
var1 dq 255.0

section .text
bits 64
default rel
global imgCvtGrayDoubleToInt

imgCvtGrayDoubleToInt:
    ; height @ rcx
    ; width  @ rdx
    ; arr    @ r8
    ; output @ r9
    XOR RSI, RSI              ; RSI: Row counter
L1:
    CMP RSI, RCX              ; If row count >= height
    JGE FINIS                

    XOR RDI, RDI              ; RDI: Col counter
L2:
    CMP RDI, RDX              ; If col count >= width
    JGE NEXT_ROW              

    MOV RAX, RSI
    IMUL RAX, RDX             ; RAX: i * width
    ADD RAX, RDI              ; RAX: i * width + j
    SHL RAX, 3                ; RAX:(i * width + j) * 8

    MOVSD XMM0, [R8 + RAX]    ; XMM0: nth element

    MOVSD XMM1, [var1]        ; XMM1: 255.0
    MULSD XMM0, XMM1          

    CVTSD2SI RAX, XMM0        ; RAX: Stores the converted double

    MOV RBX, RSI
    IMUL RBX, RDX             ; RBX: i * width
    ADD RBX, RDI              ; RBX: i * width + j
    MOV [R9 + RBX], AL        

    INC RDI
    JMP L2                    
NEXT_ROW:
    INC RSI
    JMP L1                    
FINIS:
    RET
