; Nasm version of GCC sum.c
;    compile with:
;	nasm -f elf64 -o sum.o sum.asm
;	gcc -o sum sum.o
;	./sum

        bits    64

; initialized data section -----------------------------
        section .data

; cstring literals

L_.str:         db      "%d",0
L_.str.1:       db      " ",0
L_.str.2:       db      "\n",0

; uninitialized data (zero filled) ---------------------
        section .bss

_fmt            resq        1
_cnt            resd        1
_sum            resd        1
_flag           resd        1

; code section ------------------------------------------
        section .text
        global  main

display:
        push    rbp
        mov     rbp, rsp
Ltmp2:
        sub     rsp, 16
        ;
        add     rsp, 16
        pop     rbp
        ret

main:
        push rbp
        mov     rbp, rsp
        sub     rsp, 6
        ;
        add     rsp, 16
        pop     rbp
        ret


