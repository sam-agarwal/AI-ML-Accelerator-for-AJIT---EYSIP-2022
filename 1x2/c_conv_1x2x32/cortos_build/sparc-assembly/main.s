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
	ld	[%g1+%lo(n)], %i0
	cmp	%i0, 0
	ble	.L35
	 sethi	%hi(init_00), %g1
	add	%i0, -1, %g4
	sethi	%hi(img), %g3
	and	%g4, -2, %g4
	or	%g3, %lo(img), %g3
	mov	0, %i5
	add	%g4, 2, %g4
.L6:
	mov	0, %g1
	add	%g1, 1, %g2
.L36:
	stb	%g2, [%g3+%g1]
	add	%g1, 2, %g1
	cmp	%g1, %g4
	bne	.L36
	 add	%g1, 1, %g2
	add	%i5, 1, %i5
	cmp	%i5, %i0
	bne	.L6
	 add	%g3, %i0, %g3
	sethi	%hi(init_00), %g1
.L35:
	mov	1, %g2
	st	%g2, [%g1+%lo(init_00)]
	sethi	%hi(init_01), %g1
	or	%g1, %lo(init_01), %g1
.L7:
	ld	[%g1], %g2
	cmp	%g2, 0
	be	.L7
	 nop
	sethi	%hi(res_rows), %g1
	ld	[%g1+%lo(res_rows)], %l2
	cmp	%l2, 0
	ble	.L33
	 sethi	%hi(res_cols), %g1
	sethi	%hi(img), %l0
	ld	[%g1+%lo(res_cols)], %l1
	or	%l0, %lo(img), %l0
	add	%l1, -1, %o0
	sethi	%hi(kernel_size), %g1
	and	%o0, -2, %o0
	add	%l0, 2, %l3
	sethi	%hi(res), %l4
	ld	[%g1+%lo(kernel_size)], %i5
	mov	0, %o2
	mov	0, %o4
	mov	0, %o1
	or	%l4, %lo(res), %l4
	add	%l3, %o0, %l3
	sethi	%hi(kernel), %o5
.L16:
	cmp	%l1, 0
	ble,a	.L37
	 add	%o1, 1, %o1
	sll	%o4, 2, %i1
	add	%o2, %l0, %o7
	add	%i1, %l4, %i1
	add	%o2, %l3, %o3
.L15:
	cmp	%i5, 0
	ble,a	.L38
	 add	%o7, 2, %o7
	or	%o5, %lo(kernel), %i3
	mov	%o7, %i4
	mov	0, %i2
.L14:
	ld	[%i1], %g2
	mov	0, %g1
.L13:
	ldub	[%i3+%g1], %g4
	ldub	[%i4+%g1], %g3
	add	%g1, 1, %g1
	smul	%g4, %g3, %g3
	cmp	%g1, %i5
	bne	.L13
	 add	%g2, %g3, %g2
	st	%g2, [%i1]
	add	%i2, 1, %i2
	add	%i3, %i5, %i3
	cmp	%i2, %i5
	bne	.L14
	 add	%i4, %i0, %i4
	add	%o7, 2, %o7
.L38:
	cmp	%o7, %o3
	bne	.L15
	 add	%i1, 8, %i1
	add	%o4, 2, %o4
	add	%o4, %o0, %o4
	add	%o1, 1, %o1
.L37:
	add	%o4, -1, %o4
	cmp	%o1, %l2
	bne	.L16
	 add	%o2, %i0, %o2
.L33:
	sethi	%hi(b), %g1
	or	%g1, %lo(b), %g1
.L22:
	ld	[%g1], %g2
	cmp	%g2, 0
	be	.L22
	 nop
	ld	[%g1], %i0
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
	ld	[%g1+%lo(n)], %i0
	cmp	%i0, 0
	ble,a	.L67
	 sethi	%hi(init_01), %g1
	add	%i0, -2, %g4
	sethi	%hi(img), %g3
	and	%g4, -2, %g4
	or	%g3, %lo(img), %g3
	mov	0, %i5
	add	%g4, 3, %g4
.L43:
	cmp	%i0, 1
	be	.L44
	 mov	1, %g1
	add	%g1, 1, %g2
.L68:
	stb	%g2, [%g3+%g1]
	add	%g1, 2, %g1
	cmp	%g1, %g4
	bne	.L68
	 add	%g1, 1, %g2
.L44:
	add	%i5, 1, %i5
	cmp	%i5, %i0
	bne	.L43
	 add	%g3, %i0, %g3
	sethi	%hi(init_01), %g1
.L67:
	mov	1, %g2
	st	%g2, [%g1+%lo(init_01)]
	sethi	%hi(init_00), %g1
	or	%g1, %lo(init_00), %g1
.L45:
	ld	[%g1], %g2
	cmp	%g2, 0
	be	.L45
	 nop
	sethi	%hi(res_rows), %g1
	ld	[%g1+%lo(res_rows)], %l1
	cmp	%l1, 0
	ble	.L54
	 sethi	%hi(res_cols), %g1
	sethi	%hi(kernel_size), %g2
	ld	[%g1+%lo(res_cols)], %l0
	sethi	%hi(res), %l4
	add	%l0, -2, %o0
	sethi	%hi(img), %g1
	and	%o0, -2, %o0
	or	%g1, %lo(img), %g1
	ld	[%g2+%lo(kernel_size)], %i5
	add	%g1, 3, %l2
	mov	0, %o2
	mov	1, %o4
	mov	0, %o1
	or	%l4, %lo(res), %l4
	add	%g1, 1, %l3
	add	%l2, %o0, %l2
	sethi	%hi(kernel), %o5
.L53:
	cmp	%l0, 1
	ble,a	.L69
	 add	%o1, 1, %o1
	sll	%o4, 2, %i1
	add	%l3, %o2, %o7
	add	%i1, %l4, %i1
	add	%o2, %l2, %o3
.L52:
	cmp	%i5, 0
	ble,a	.L70
	 add	%o7, 2, %o7
	or	%o5, %lo(kernel), %i3
	mov	%o7, %i4
	mov	0, %i2
.L51:
	ld	[%i1], %g2
	mov	0, %g1
.L50:
	ldub	[%i3+%g1], %g4
	ldub	[%i4+%g1], %g3
	add	%g1, 1, %g1
	smul	%g4, %g3, %g3
	cmp	%g1, %i5
	bne	.L50
	 add	%g2, %g3, %g2
	st	%g2, [%i1]
	add	%i2, 1, %i2
	add	%i3, %i5, %i3
	cmp	%i2, %i5
	bne	.L51
	 add	%i4, %i0, %i4
	add	%o7, 2, %o7
.L70:
	cmp	%o7, %o3
	bne	.L52
	 add	%i1, 8, %i1
	add	%o4, 2, %o4
	add	%o4, %o0, %o4
	add	%o1, 1, %o1
.L69:
	add	%o4, 1, %o4
	cmp	%o1, %l1
	bne	.L53
	 add	%o2, %i0, %o2
.L54:
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
	ble	.L82
	 mov	0, %l1
	sethi	%hi(.LC0), %i3
	sethi	%hi(.LC1), %l2
	add	%i2, -1, %l3
	or	%i3, %lo(.LC0), %i3
	or	%l2, %lo(.LC1), %l2
	cmp	%i2, 0
.L80:
	ble	.L75
	 nop
	sll	%l1, 2, %i5
	mov	0, %i4
	add	%i0, %i5, %i5
.L74:
	ld	[%i5], %o1
	call	cortos_printf, 0
	 mov	%i3, %o0
	add	%i4, 1, %i4
	cmp	%i4, %i2
	bne	.L74
	 add	%i5, 4, %i5
	add	%l1, 1, %l1
	add	%l1, %l3, %l1
.L75:
	call	cortos_printf, 0
	 mov	%l2, %o0
	add	%l0, 1, %l0
	cmp	%l0, %i1
	bne	.L80
	 cmp	%i2, 0
.L82:
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
	.ident	"GCC: (Buildroot 2014.08) 4.7.4"
	.section	.note.GNU-stack,"",@progbits
