	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.intel_syntax noprefix
	.globl	_display
	.align	4, 0x90
_display:                               ## @display
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	rax, qword ptr [rip + _fmt@GOTPCREL]
	mov	rcx, qword ptr [rip + _cnt@GOTPCREL]
	mov	rdx, qword ptr [rip + _msg1]
	mov	qword ptr [rax], rdx
	mov	esi, dword ptr [rcx]
	mov	dword ptr [rip + _pdata], esi
	mov	rdi, qword ptr [rax]                    ; first param 
	mov	esi, dword ptr [rip + _pdata]           ; second param
	mov	al, 0                                   ; num vector regs used
	call	_printf
	mov	rcx, qword ptr [rip + _fmt@GOTPCREL]
	mov	rdx, qword ptr [rip + _msg2]
	mov	qword ptr [rcx], rdx
	mov	rdi, qword ptr [rcx]
	mov	dword ptr [rbp - 4], eax ## 4-byte Spill
	mov	al, 0
	call	_printf
	mov	rcx, qword ptr [rip + _fmt@GOTPCREL]
	mov	rdx, qword ptr [rip + _sum@GOTPCREL]
	mov	rdi, qword ptr [rip + _msg1]
	mov	qword ptr [rcx], rdi
	mov	esi, dword ptr [rdx]
	mov	dword ptr [rip + _pdata], esi
	mov	rdi, qword ptr [rcx]
	mov	esi, dword ptr [rip + _pdata]
	mov	dword ptr [rbp - 8], eax ## 4-byte Spill
	mov	al, 0
	call	_printf
	mov	rcx, qword ptr [rip + _fmt@GOTPCREL]
	mov	rdx, qword ptr [rip + _msg3]
	mov	qword ptr [rcx], rdx
	mov	rdi, qword ptr [rcx]
	mov	dword ptr [rbp - 12], eax ## 4-byte Spill
	mov	al, 0
	call	_printf
	mov	dword ptr [rbp - 16], eax ## 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp5:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	rax, qword ptr [rip + _cnt@GOTPCREL]
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rax], 0
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rip + _flag@GOTPCREL]
	mov	rcx, qword ptr [rip + _cnt@GOTPCREL]
	cmp	dword ptr [rcx], 9
	sete	dl
	and	dl, 1
	movzx	esi, dl
	mov	dword ptr [rax], esi
	cmp	dword ptr [rax], 0
	je	LBB1_3
## BB#2:
	jmp	LBB1_7
LBB1_3:                                 ##   in Loop: Header=BB1_1 Depth=1
	mov	rax, qword ptr [rip + _flag@GOTPCREL]
	cmp	dword ptr [rip + _odd], 0
	sete	cl
	and	cl, 1
	movzx	edx, cl
	mov	dword ptr [rax], edx
	cmp	dword ptr [rax], 0
	je	LBB1_5
## BB#4:                                ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_6
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	mov	rax, qword ptr [rip + _sum@GOTPCREL]
	mov	rcx, qword ptr [rip + _cnt@GOTPCREL]
	mov	rdx, qword ptr [rip + _dptr]
	movsxd	rcx, dword ptr [rcx]
	mov	esi, dword ptr [rdx + 4*rcx]
	add	esi, dword ptr [rax]
	mov	dword ptr [rax], esi
LBB1_6:                                 ##   in Loop: Header=BB1_1 Depth=1
	mov	rax, qword ptr [rip + _cnt@GOTPCREL]
	cmp	dword ptr [rip + _odd], 0
	setne	cl
	xor	cl, -1
	and	cl, 1
	movzx	edx, cl
	mov	dword ptr [rip + _odd], edx
	mov	edx, dword ptr [rax]
	add	edx, 1
	mov	dword ptr [rax], edx
	call	_display
	jmp	LBB1_1
LBB1_7:
	call	_display
	mov	eax, dword ptr [rbp - 4]
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc

	.section	__DATA,__data
	.globl	_data                   ## @data
	.align	4
_data:
	.long	5                       ## 0x5
	.long	3                       ## 0x3
	.long	7                       ## 0x7
	.long	10                      ## 0xa
	.long	42                      ## 0x2a
	.long	6                       ## 0x6
	.long	22                      ## 0x16
	.long	15                      ## 0xf
	.long	32                      ## 0x20

	.globl	_dptr                   ## @dptr
	.align	3
_dptr:
	.quad	_data

	.globl	_odd                    ## @odd
.zerofill __DATA,__common,_odd,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

	.section	__DATA,__data
	.globl	_msg1                   ## @msg1
	.align	3
_msg1:
	.quad	L_.str

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	" "

	.section	__DATA,__data
	.globl	_msg2                   ## @msg2
	.align	3
_msg2:
	.quad	L_.str.1

	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"\n"

	.section	__DATA,__data
	.globl	_msg3                   ## @msg3
	.align	3
_msg3:
	.quad	L_.str.2

	.globl	_pdata                  ## @pdata
.zerofill __DATA,__common,_pdata,4,2
	.comm	_fmt,8,3                ## @fmt
	.comm	_cnt,4,2                ## @cnt
	.comm	_sum,4,2                ## @sum
	.comm	_flag,4,2               ## @flag

.subsections_via_symbols
