; Hello for Nasm

    global  main
    extern  puts

    section .data
msg:    db  "Hello, COSC2325 developer!\n",0

    section    .text
main:
        push    rbp
        mov     rbp, rsp
        ;----------------
        mov     rdi, msg
        call    puts
        ;----------------
        mov     eax,0
        pop     rbp
        ret

