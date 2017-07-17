%include "/usr/local/lib/asm_io.inc"

        segment .data
sep     db  ", ",0
ROWS    equ 3
COLS    equ 4
ROWSZ   equ COLS*8

grades  dq  10,20,30,40
        dq  50,60,70,80
        dq  90,100,110,120

        segment .text
        global  asm_main

asm_main:
        mov     rcx, ROWS
        mov     rbx, 0          ; row number
ColLoop:
        mov     rsi, 0          ; column number
        push    rcx             ; save row counter
        push    rbx             ; sabe base address for this row
        mov     rcx, COLS       ; set for column loop
RowLoop:
        mov     rdi, [grades + rbx + rsi * 8]
        push    rsi
        push    rcx
        call    print_int
        mov     rdi, sep
        call    print_string
        pop     rcx
        pop     rsi
        inc     rsi
        loop    RowLoop
        call    print_nl
        pop     rbx             ; recover row base
        pop     rcx             ; and current row counter
        add     rbx, ROWSZ      ; add offset to next row
        loop    ColLoop         ; loop back for another row
        mov     rax, 0
        ret
