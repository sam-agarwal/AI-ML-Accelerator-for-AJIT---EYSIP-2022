	.file	"main.c"
	.section	.text.startup,"ax",@progbits
	.align 4
	.global main
	.type	main, #function
	.proc	020
main:
	jmp	%o7+8
	 nop
	.size	main, .-main
	.section	".text"
	.align 4
	.global ajit_entry_func_001
	.type	ajit_entry_func_001, #function
	.proc	020
ajit_entry_func_001:
	save	%sp, -96, %sp
	sethi	%hi(n), %g1
	ld	[%g1+%lo(n)], %o2
	cmp	%o2, 0
	ble	.L4
	 sethi	%hi(img), %o0
	add	%o2, -1, %g4
	or	%o0, %lo(img), %g3
	and	%g4, -2, %g4
	mov	0, %i5
	add	%g4, 2, %g4
.L6:
	mov	0, %g1
	add	%g1, 1, %g2
.L20:
	stb	%g2, [%g3+%g1]
	add	%g1, 2, %g1
	cmp	%g1, %g4
	bne	.L20
	 add	%g1, 1, %g2
	add	%i5, 1, %i5
	cmp	%i5, %o2
	bne	.L6
	 add	%g3, %o2, %g3
.L4:
	mov	1, %g2
	sethi	%hi(init_00), %g1
	st	%g2, [%g1+%lo(init_00)]
	sethi	%hi(init_01), %g2
	or	%g2, %lo(init_01), %g2
.L7:
	ld	[%g2], %g1
	cmp	%g1, 0
	be	.L7
	 mov	4, %o1
	or	%o0, %lo(img), %o0
	sethi	%hi(kernel), %o3
	sethi	%hi(res), %o4
	or	%o3, %lo(kernel), %o3
	call	conv_even, 0
	 or	%o4, %lo(res), %o4
	sethi	%hi(b), %g2
	or	%g2, %lo(b), %g2
.L8:
	ld	[%g2], %g1
	cmp	%g1, 0
	be	.L8
	 nop
	ld	[%g2], %i0
	call	cortos_exit, 0
	 restore
	.size	ajit_entry_func_001, .-ajit_entry_func_001
	.align 4
	.global ajit_entry_func_010
	.type	ajit_entry_func_010, #function
	.proc	020
ajit_entry_func_010:
	save	%sp, -96, %sp
	sethi	%hi(n), %g1
	ld	[%g1+%lo(n)], %o2
	cmp	%o2, 0
	ble	.L23
	 sethi	%hi(img), %o0
	add	%o2, -2, %g4
	or	%o0, %lo(img), %g3
	and	%g4, -2, %g4
	mov	0, %i5
	add	%g4, 3, %g4
.L25:
	cmp	%o2, 1
	be	.L26
	 mov	1, %g1
	add	%g1, 1, %g2
.L36:
	stb	%g2, [%g3+%g1]
	add	%g1, 2, %g1
	cmp	%g1, %g4
	bne	.L36
	 add	%g1, 1, %g2
.L26:
	add	%i5, 1, %i5
	cmp	%i5, %o2
	bne	.L25
	 add	%g3, %o2, %g3
.L23:
	mov	1, %g2
	sethi	%hi(init_01), %g1
	st	%g2, [%g1+%lo(init_01)]
	sethi	%hi(init_00), %g2
	or	%g2, %lo(init_00), %g2
.L27:
	ld	[%g2], %g1
	cmp	%g1, 0
	be	.L27
	 mov	4, %o1
	or	%o0, %lo(img), %o0
	sethi	%hi(kernel), %o3
	sethi	%hi(res), %o4
	or	%o3, %lo(kernel), %o3
	call	conv_odd, 0
	 or	%o4, %lo(res), %o4
	sethi	%hi(b), %g1
	mov	1, %g2
	st	%g2, [%g1+%lo(b)]
	ld	[%g1+%lo(b)], %i0
	call	cortos_exit, 0
	 restore
	.size	ajit_entry_func_010, .-ajit_entry_func_010
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.asciz	"%d "
	.align 8
.LC1:
	.asciz	"\n"
	.section	".text"
	.align 4
	.global print_matrix
	.type	print_matrix, #function
	.proc	020
print_matrix:
	save	%sp, -96, %sp
	mov	0, %l0
	cmp	%i1, 0
	ble	.L48
	 mov	0, %l1
	sethi	%hi(.LC0), %i3
	sethi	%hi(.LC1), %l2
	add	%i2, -1, %l3
	or	%i3, %lo(.LC0), %i3
	or	%l2, %lo(.LC1), %l2
	cmp	%i2, 0
.L46:
	ble	.L41
	 nop
	sll	%l1, 2, %i5
	mov	0, %i4
	add	%i0, %i5, %i5
.L40:
	ld	[%i5], %o1
	call	cortos_printf, 0
	 mov	%i3, %o0
	add	%i4, 1, %i4
	cmp	%i4, %i2
	bne	.L40
	 add	%i5, 4, %i5
	add	%l1, 1, %l1
	add	%l1, %l3, %l1
.L41:
	call	cortos_printf, 0
	 mov	%l2, %o0
	add	%l0, 1, %l0
	cmp	%l0, %i1
	bne	.L46
	 cmp	%i2, 0
.L48:
	jmp	%i7+8
	 restore
	.size	print_matrix, .-print_matrix
	.global res_cols
	.section	".data"
	.align 4
	.type	res_cols, #object
	.size	res_cols, 4
res_cols:
	.long	45
	.global res_rows
	.align 4
	.type	res_rows, #object
	.size	res_rows, 4
res_rows:
	.long	45
	.global n
	.align 4
	.type	n, #object
	.size	n, 4
n:
	.long	48
	.global kernel_size
	.align 4
	.type	kernel_size, #object
	.size	kernel_size, 4
kernel_size:
	.long	4
	.global kernel
	.align 8
	.type	kernel, #object
	.size	kernel, 16
kernel:
	.byte	1
	.byte	0
	.byte	0
	.byte	1
	.byte	0
	.byte	1
	.byte	1
	.byte	0
	.byte	0
	.byte	1
	.byte	1
	.byte	0
	.byte	1
	.byte	0
	.byte	0
	.byte	1
	.common	img,2304,8
	.common	res,8100,8
	.global b
	.section	".bss"
	.align 4
	.type	b, #object
	.size	b, 4
b:
	.skip	4
	.global init_01
	.align 4
	.type	init_01, #object
	.size	init_01, 4
init_01:
	.skip	4
	.global init_00
	.align 4
	.type	init_00, #object
	.size	init_00, 4
init_00:
	.skip	4
	.ident	"GCC: (Buildroot 2014.08-g538713e-dirty) 4.7.4"
	.section	.note.GNU-stack,"",@progbits
