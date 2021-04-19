NUM1  DATA  50H
NUM2  DATA  51H
OUT1  DATA  53H
OUT2  DATA  54H
ORG 0000H
    AJMP START
ORG 0100H
START:
    MOV NUM1, #12H      ;NUM1 = 12H
    MOV NUM2, #21H      ;NUM2 = 21H
        
    MOV A, NUM1         ;A 赋值为NUM1
    ADD A, NUM2         ;A 值为 NUM1 + NUM2
    MOV OUT1, A         ;OUT1 = NUM1 + NUM2 加法完成
        
    MOV A, NUM1         ;A 赋值为 NUM1
    CLR C               ;清空 C
    SUBB A, NUM2        ;比较减法 A = (A) - (NUM2) - (CY)
    JB ACC.7, SMALL     ;如果符号位是 1 跳转到 SMALL,意味 NUM1 < NUM2
    JZ EQUAL            ;如果相减后结果为 0 跳转到 EQUAL,意味 NUM1 = NUM2
    AJMP BIG            ;如果不是上述两种情况，则跳转到 BIG,意味 NUM1 > NUM2
SMALL:
    MOV R1, #1
    AJMP NEXT
EQUAL:
    MOV R1, #0
    AJMP NEXT
BIG:
    MOV R1, #2
    AJMP NEXT
    
NEXT:
    MOV R2, #10         ;R2 = 10
    MOV A, #0           ;A = 0 (清零)
LOOP1:
    ADD A, R2           ;A = A + R2
    DJNZ R2, LOOP1      ;R2 减 1,如果不为零,回到LOOP1,实现 A 从 10 加到 1
    MOV OUT2, A         ;OUT2 = A 累加完成
        
    MOV A, NUM1
    MOV B, NUM2
    MUL AB              ;乘法,A 为低字节,B 为高字节
    MOV OUT1, A
    MOV OUT2, B
        
    SJMP $
    END