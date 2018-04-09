	.file	"packer.c"
	.text
	.globl	print_HW
	.type	print_HW, @function
print_HW:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
#APP
# 9 "packer.c" 1
	mov  $0x0A21646C72, %rax
push %rax
mov  $0x6F57206F6C6C6548, %rax
push %rax
mov %rsp, %rsi
mov $0x1, %rax
mov $0x1, %rdi
mov $0x0D, %rdx
syscall

# 0 "" 2
#NO_APP
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	print_HW, .-print_HW
	.globl	pack_XOR
	.type	pack_XOR, @function
pack_XOR:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%r8, -48(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	movl	-28(%rbp), %eax
	movl	$0, %edx
	divl	-32(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L4
	movl	-28(%rbp), %eax
	movl	$0, %edx
	divl	-32(%rbp)
	movl	%edx, %eax
	jmp	.L5
.L4:
	movl	-32(%rbp), %eax
.L5:
	movl	%eax, -8(%rbp)
	movl	-28(%rbp), %eax
	subl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L6
.L9:
	movl	$0, -12(%rbp)
	jmp	.L7
.L8:
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %esi
	movl	-12(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %ecx
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	xorl	%ecx, %esi
	movl	%esi, %edx
	movb	%dl, (%rax)
	addl	$1, -12(%rbp)
.L7:
	movl	-12(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jb	.L8
	movl	-32(%rbp), %eax
	addl	%eax, -16(%rbp)
.L6:
	movl	-16(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jb	.L9
	movl	$0, -12(%rbp)
	jmp	.L10
.L11:
	movl	-4(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %esi
	movl	-12(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %ecx
	movl	-4(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	xorl	%ecx, %esi
	movl	%esi, %edx
	movb	%dl, (%rax)
	addl	$1, -12(%rbp)
.L10:
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jb	.L11
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	pack_XOR, .-pack_XOR
	.section	.rodata
.LC0:
	.string	"%02X"
	.text
	.globl	print_buff
	.type	print_buff, @function
print_buff:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L13
.L14:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L13:
	movl	-4(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	ja	.L14
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	print_buff, .-print_buff
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	print_HW
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.2.0-8ubuntu3.2) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
