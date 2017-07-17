; hello.asm - basic NASM assembly language program

        bits 64
        global  main
        extern  puts

        section .data
message db      "Hello, COSC2425 Programmer!", 10, 0

        section .text
main:
        ; function setup
        push    rbp
        mov     rbp, rsp
        
	; user code goes here
        mov     rdi, message		; point to the message
        call    puts			; call puts to print string

        ; function return
        mov     eax, 0
        pop     rbp
        ret

