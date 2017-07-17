%include "/usr/local/lib/asm_io.inc"

        section     .data
msg     db          "Factorial demo",0
res_msg db          "Factorial of ",0
val_msg db          " is ",0

        section     .text
        global      asm_main
asm_main:
        lea         rdi, [rel msg]
        mov         al, 0
        call        printf
        call        print_nl

floop:  call        read_int
        cmp         rax, 0
        jl          fend
        ;                           do the factorial of this number
        push        rax             ; N is on stack (do not trust procedures!)
        lea         rdi, [rel res_msg]    ; display result string
        mov         al, 0
        call        printf
        pop         rdi             ; N is in rdi
        push        rdi             ; N is back on stack
        call        print_int       ; display N
        pop         rax             ; recover parameter
        call        factorial       ; go calculate factorial
        push        rax             ; save F(N) on stack
        lea         rdi, [rel val_msg]    ;
        mov         al, 0
        call        printf
        pop         rdi             ; back in RDI
        call        print_int
        call        print_nl
        jmp         floop           ; back for another round
fend:
        mov         rax, 0
        ret

; factorial: recursive function
;   input RAX: number to evaluate
;   output RAX: - result
;   no other registers modified
;
factorial:
        push        rbx         ; save caller's registers
        push        rdx         ; zapped by multiply
        cmp         rax, 0      ; base case
        jnz         non_base
base_case:
        mov         rax, 1      ; set value
        jmp         f_exit
        ;
non_base:
        push        rax         ; save N for later
        dec         rax         ; calculate N-1
        call        factorial   ; recursive call
        pop         rbx         ; recover N
        mul         rbx         ; n * f(N-1) into RAX
f_exit:
        pop         rdx         ; recover user registers
        pop         rbx
        ret                     ; back with answer in RAX

print_nl:
        lea         rdi, [rel crlf]
        mov         al, 0
        call        printf
        ret

        
