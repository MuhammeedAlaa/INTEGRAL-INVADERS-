YWN MACRO WDTH,HEGITH,STARTX,STARTY,COLOR
LOCAL ROW, COL,C, CON2,CLM,CLMN,RW,RWN

PUSH AX
PUSH CX
PUSH DX
PUSH BX
PUSH SI
PUSH DI



       ;INITAL POINT
    MOV DX,STARTY ; Y = 250
    MOV CX,STARTX ; X = 400

    MOV AL,COLOR
    MOV AH,0CH
  
    ;{ THIS DRAW ALL VERTICAL LINES OF GHOST WORD
    ROW: 

        COL:
        ;{ IF(S) WE HANDLE IT'S VERTICAL LINES 
                CMP DX,STARTY + HEGITH / 2
                JA C
                INT 10H
                ADD CX, WDTH - 10
                INT 10H
                SUB CX,WDTH - 10
                JMP CON2
                C: 
                ADD CX,WDTH / 2
                SUB CX,5
                INT 10H 
                ADD CX,5
                SUB CX,WDTH / 2
            ;}


         CON2:
         ;{     
                ADD CX,WDTH + 10
                INT 10H
                ADD CX,WDTH -10
                INT 10H
         
         ;}
         ;{
            ADD CX,20
            INT 10H
            ADD CX,WDTH -10
            INT 10H
         ;}

         ;{
            ADD CX,30
            INT 10H
            ADD CX,WDTH/2
            SUB CX,5
            INT 10H
            SUB CX,WDTH/2
            ADD CX,5
            ADD CX,WDTH -10
            INT 10H
         ;}
         ;{
            ADD CX,20
            INT 10H
            ADD CX,WDTH -10
            INT 10H
         ;}


          ;{
                 ADD CX,20
                 INT 10H
                 ADD CX,WDTH - 7
                 INT 10H         
           ;}
         SUB CX,6*WDTH + 53
    JMP CON10
    SKIP10: JMP LOSS 
    CON10:
        INC DX
        CMP DX,STARTY + HEGITH
        JNZ COL
    MOV DX,STARTY      
    INC CX
    CMP CX,STARTX + 10
    JNZ ROW    
    ;}
 
    ; BACK TO INTAIL POINT TO DRAW HORIZONTAL 
    MOV CX,STARTX
    MOV DX,STARTY + HEGITH / 2
    ;{ THIS BLOCK JUST DRAW HORIZONTAL LINES OF GHOST WORD
    CLM: 
        RW:
        ;{ HORIZONTAL LINS OF 'G'
            INT 10H
        ;}

        ;{
            ADD DX,HEGITH / 2 - 10
            ADD CX, WDTH + 10
            INT 10H
            SUB DX, HEGITH - 10
            INT 10H
            ADD DX,HEGITH -10
        ;}

        ;{
            ADD CX,WDTH + 10
            INT 10H
        ;}

        ;{
            ADD CX,WDTH + 20
            INT 10H
        ;}
        ;{
            ADD CX,WDTH + 10
            INT 10H
            SUB DX,HEGITH -10
            INT 10H
        ;}

        ;{
            SUB CX,4*WDTH+50
            ADD DX,HEGITH/2
        ;}
        INC CX
        CMP CX,STARTX + WDTH
        JNZ RW
    MOV CX,STARTX
    INC DX
    CMP DX,STARTY + HEGITH / 2 + 10
    JNZ CLM
; }

    MOV CX,STARTX + 5* WDTH + 70 
    MOV DX,STARTY
    MOV SI,STARTY
    ;{ THIS BLOCK JUST DRAW HORIZONTAL LINES OF GHOST WORD
    CLMN: 
        RWN:
        ;{ HORIZONTAL LINS OF 'N'
            INT 10H
        ;}
            INC CX
            INC DX
            CMP CX,STARTX + 6* WDTH + 57
        JNZ RWN
            ADD SI,1
            MOV CX,STARTX + 5* WDTH + 70
            MOV DX,SI
            CMP DX,STARTY + 14
    JNZ CLMN
;}

POP DI
POP SI
POP BX
POP DX
POP CX
POP AX

ENDM YWN