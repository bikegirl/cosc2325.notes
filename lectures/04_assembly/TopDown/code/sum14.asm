; simple summer
;    compile with:
;	nasm -f elf64 -o sum.o sum.asm
;	gcc -o sum sum.o
;	./sum
;
; initialized data section --------------------------------
	section .data
data	dd	5,3,7,10,42,6,22,15,32
dptr	dq	data		; pointer to arrat
odd	dd	0
sum	dd	0
msg1:	db	"%d", 0		; integer format string
msg2:	db	" ", 0		; space
msg3:	db	0ah, 0		; newline
fmt	dd	0		; pointer to format string
pdata	dq	0		; pointer 

; uninitialized data section ------------------------------
	section	.bss
cnt	resd	1
flag	resd	1

; code section --------------------------------------------
	section .text
	global	main
	extern	printf
display:
	mov	rdi, msg1	; rdi has format string address
	mov	rsi, [cnt]	; rsi has value to print
	mov	rax, 0		; required
	call	printf		; print cnt
	mov	rdi, msg2
	mov	rax, 0
	call 	printf		; then a spaceDD
	mov	rdi, msg1
	mov	rsi, [sum]	
	mov	rax, 0
	call 	printf		; print sum
	mov	rdi, msg3
	mov 	rax, 0
	call 	printf		; newline
	ret
main:
	mov	eax, 0		; get a 32 bit zero
	mov	[cnt], eax	; initialize cnt
	;
l1:	mov	eax, [cnt]	; get current count
	cmp	eax, 9		; hit the end yet?
	jz	l3		; end if so
	mov	eax, [odd]	; fetch current value of odd
	cmp	eax, 0		; is it zero
	jz	l2;
	;
	mov	rax, 0		; make 64 bit zero
	mov	eax, [cnt]	; load in current count
	mov	ecx, 4		; multiply by 4 bytes
	mul	ecx
	mov	rbx, [dptr]	; fetch pointer to array
	add	rbx, rax	; add offset to number
	mov	eax, dword [rbx]	; fetch item from array 
	add	[sum], eax	; add this one in
	;
l2:
	not	dword [odd]		; flip the boolean
	inc	dword [cnt]		; bump the counter
	call	display
	jmp	l1
l3:	mov	rax, 0
	ret
