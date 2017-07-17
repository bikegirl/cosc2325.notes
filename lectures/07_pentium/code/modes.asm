%include "/usr/local/lib/asm_io.inc"

        segment .data

mydata  dq      0x1111111111111111
        dq      0x2222222222222222
        dq      0x3333333333333333
        dq      0x4444444444444444
        dq      0x5555555555555555

        segment .bss

mydata2 resq    1


        segment .text
        global  asm_main

        DEFAULT ABS

asm_main:

        mov     rax, mydata             ; immediate addressing
        mov     rbx, rax                ; register addressing
        ;
        mov     rdi, rbx
        call    print_qword
        call    print_nl
        ;
        mov     rax, [mydata]           ; direct memory reference
        mov     [mydata2], rax          ; direct memory reference
        ;
        mov     rdi, [mydata2]
        call    print_qword
        call    print_nl
        ;
        mov     rbx, mydata2            ; load address
        mov     rax, [rbx]              ; register indirect reference
        ;
        mov     rdi, rax
        call    print_qword
        call    print_nl
        ;
        mov     rbx, mydata             ; load base register
        mov     rax, [rbx + 4]          ; based indirect reference
        mov     rax, [rbx + 8]          ; another example
        add     rbx, 16                 ; move rbx down 16
        mov     rax, [rbx - 16]         ; offset is negative
        ;
        mov     rdi, rax
        call    print_qword
        call    print_nl
        ;
        mov     rsi, 0                  ; load index with 0
        mov     rax, [mydata + rsi*8]   ; indexed reference
        inc     rsi
        mov     rbx, [mydata + rsi * 8] ;
        ;
        mov     rdi, rbx
        call    print_qword
        call    print_nl
        ;
        mov     rbx, mydata             ; load base register
        mov     rsi, 0                  ; load index register
        mov     rax, [rbx + rsi]        ; bases indexed reference
        mov     rbx, [rbx + rsi + 8]    ; 
        ;
        mov     rdi, rbx
        call    print_qword
        call    print_nl
        ;
        mov     rbx, mydata             ; load base register
        mov     rsi, 0                  ; load index register
        mov     rax, [rbx + rsi * 8 + 8]; based indexed scaled reference
        inc     rsi
        mov     rcx, [rbx + rsi * 8 + 8]
        ;
        mov     rdi, rcx
        call    print_qword
        call    print_nl
        mov     rax, 0
        ret 
