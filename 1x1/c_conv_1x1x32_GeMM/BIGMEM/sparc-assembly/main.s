	.file	"main.c"
	.section	".text"
	.align 4
	.global enable_serial
	.type	enable_serial, #function
	.proc	020
enable_serial:
	mov	7, %o0
	or	%o7, %g0, %g1
	call	__ajit_write_serial_control_register__, 0
	 or	%g1, %g0, %o7
	.size	enable_serial, .-enable_serial
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
	ble	.L14
	 mov	0, %l1
	sethi	%hi(.LC0), %i3
	sethi	%hi(.LC1), %l2
	add	%i2, -1, %l3
	or	%i3, %lo(.LC0), %i3
	or	%l2, %lo(.LC1), %l2
	cmp	%i2, 0
.L12:
	ble	.L6
	 nop
	sll	%l1, 2, %i5
	mov	0, %i4
	add	%i0, %i5, %i5
.L5:
	ld	[%i5], %o1
	call	ee_printf, 0
	 mov	%i3, %o0
	add	%i4, 1, %i4
	cmp	%i4, %i2
	bne	.L5
	 add	%i5, 4, %i5
	add	%l1, 1, %l1
	add	%l1, %l3, %l1
.L6:
	call	ee_printf, 0
	 mov	%l2, %o0
	add	%l0, 1, %l0
	cmp	%l0, %i1
	bne	.L12
	 cmp	%i2, 0
.L14:
	jmp	%i7+8
	 restore
	.size	print_matrix, .-print_matrix
	.section	.rodata.str1.8
	.align 8
.LC2:
	.asciz	"main: start_time=%d, end_time=%d, elapsed=%d\n"
	.section	.text.startup,"ax",@progbits
	.align 4
	.global main
	.type	main, #function
	.proc	020
main:
	save	%sp, -144, %sp
	sethi	%hi(img), %g3
	sethi	%hi(9216), %g4
	or	%g3, %lo(img), %g3
	or	%g4, 784, %g4
	add	%g3, %g4, %g4
	mov	0, %g1
.L17:
	add	%g1, 1, %g2
	stb	%g2, [%g3+%g1]
	cmp	%g2, 100
	bne	.L17
	 mov	%g2, %g1
	add	%g3, 100, %g3
	cmp	%g3, %g4
	bne,a	.L17
	 mov	0, %g1
	sethi	%hi(img+300), %l2
	sethi	%hi(im2col_matrix), %i1
	sethi	%hi(150528), %l7
	or	%l2, %lo(img+300), %l2
	mov	0, %l6
	or	%i1, %lo(im2col_matrix), %i1
	or	%l7, 16, %l7
.L20:
	ldub	[%l2], %l1
	ldub	[%l2+1], %i3
	ldub	[%l2+2], %i4
	ldub	[%l2-100], %l0
	ldub	[%l2-99], %i5
	ldub	[%l2-98], %o7
	ldub	[%l2-200], %o0
	ldub	[%l2-199], %g4
	ldub	[%l2-198], %i0
	ldub	[%l2-300], %o1
	ldub	[%l2-299], %g3
	ldub	[%l2-298], %i2
	add	%l6, %i1, %g1
	mov	0, %g2
	add	%l2, -300, %l5
	add	%l2, -200, %l4
	b	.L19
	 add	%l2, -100, %l3
.L23:
	mov	%o2, %i2
	mov	%o3, %i0
	mov	%o4, %o7
.L19:
	add	%g2, 1, %g2
	add	%l5, %g2, %o4
	add	%l4, %g2, %o5
	stb	%o1, [%g1]
	stb	%g3, [%g1+1]
	stb	%o0, [%g1+4]
	stb	%g4, [%g1+5]
	stb	%l0, [%g1+8]
	stb	%i5, [%g1+9]
	stb	%l1, [%g1+12]
	stb	%i3, [%g1+13]
	stb	%i4, [%g1+14]
	ldub	[%o4+2], %o2
	ldub	[%o5+2], %o3
	stb	%i2, [%g1+2]
	stb	%i0, [%g1+6]
	stb	%o7, [%g1+10]
	stb	%o2, [%g1+3]
	stb	%o3, [%g1+7]
	add	%l3, %g2, %o4
	add	%l2, %g2, %o5
	ldub	[%o4+2], %o4
	ldub	[%o5+2], %o5
	stb	%o4, [%g1+11]
	stb	%o5, [%g1+15]
	mov	%i3, %l1
	mov	%i5, %l0
	mov	%i4, %i3
	mov	%g4, %o0
	mov	%g3, %o1
	mov	%o7, %i5
	mov	%i0, %g4
	mov	%i2, %g3
	add	%g1, 16, %g1
	cmp	%g2, 97
	bne	.L23
	 mov	%o5, %i4
	add	%l6, 1552, %l6
	cmp	%l6, %l7
	bne	.L20
	 add	%l2, 100, %l2
	call	ajit_barebones_clock, 0
	 sethi	%hi(res), %i0
	sethi	%hi(kernel), %g3
	or	%g3, %lo(kernel), %g1
	ldub	[%g1+5], %o7
	st	%o7, [%fp-4]
	ldub	[%g1+6], %o7
	st	%o7, [%fp-8]
	ldub	[%g1+7], %o7
	st	%o7, [%fp-12]
	ldub	[%g1+8], %o7
	st	%o7, [%fp-16]
	ldub	[%g1+9], %o7
	st	%o7, [%fp-20]
	ldub	[%g1+10], %o7
	st	%o7, [%fp-24]
	ldub	[%g1+11], %o7
	st	%o7, [%fp-28]
	ldub	[%g1+12], %o7
	st	%o7, [%fp-32]
	ldub	[%g1+13], %o7
	ldub	[%g3+%lo(kernel)], %i2
	ldub	[%g1+1], %i3
	ldub	[%g1+4], %g3
	ldub	[%g1+2], %i4
	ldub	[%g1+3], %g4
	st	%o7, [%fp-36]
	ldub	[%g1+14], %o7
	ldub	[%g1+15], %g1
	st	%g1, [%fp-44]
	mov	%o0, %i5
	or	%i0, %lo(res), %g2
	st	%o7, [%fp-40]
	mov	%i1, %g1
	st	%g3, [%fp-48]
.L22:
	ld	[%g2], %g3
	ldub	[%g1], %l7
	smul	%l7, %i2, %l7
	add	%l7, %g3, %l7
	ld	[%fp-48], %g3
	ldub	[%g1+4], %l3
	smul	%l3, %g3, %l3
	ld	[%fp-4], %g3
	ldub	[%g1+5], %l2
	smul	%l2, %g3, %l2
	ld	[%fp-8], %g3
	ldub	[%g1+6], %l1
	smul	%l1, %g3, %l1
	ld	[%fp-12], %g3
	ldub	[%g1+7], %l0
	smul	%l0, %g3, %l0
	ld	[%fp-16], %g3
	ldub	[%g1+8], %o0
	smul	%o0, %g3, %o0
	ld	[%fp-20], %g3
	ldub	[%g1+9], %o1
	smul	%o1, %g3, %o1
	ld	[%fp-24], %g3
	ldub	[%g1+10], %o2
	smul	%o2, %g3, %o2
	ld	[%fp-28], %g3
	ldub	[%g1+11], %o3
	smul	%o3, %g3, %o3
	ld	[%fp-32], %g3
	ldub	[%g1+12], %o4
	smul	%o4, %g3, %o4
	ld	[%fp-36], %g3
	ldub	[%g1+13], %o5
	smul	%o5, %g3, %o5
	ld	[%fp-40], %g3
	ldub	[%g1+1], %l5
	ldub	[%g1+2], %l6
	ldub	[%g1+3], %l4
	ldub	[%g1+14], %o7
	ldub	[%g1+15], %i1
	smul	%o7, %g3, %o7
	smul	%l5, %i3, %l5
	smul	%l6, %i4, %l6
	add	%l7, %l5, %l5
	smul	%l4, %g4, %l4
	add	%l5, %l6, %l6
	ld	[%fp-44], %g3
	add	%l6, %l4, %l4
	smul	%i1, %g3, %i1
	add	%l4, %l3, %l3
	add	%l3, %l2, %l2
	add	%l2, %l1, %l1
	add	%l1, %l0, %l0
	add	%l0, %o0, %o0
	add	%o0, %o1, %o1
	add	%o1, %o2, %o2
	add	%o2, %o3, %o3
	add	%o3, %o4, %o4
	add	%o4, %o5, %o5
	add	%o5, %o7, %o7
	add	%o7, %i1, %i1
	st	%i1, [%g2]
	sethi	%hi(res+8100), %o7
	add	%g2, 4, %g2
	or	%o7, %lo(res+8100), %o7
	cmp	%g2, %o7
	bne	.L22
	 add	%g1, 16, %g1
	call	ajit_barebones_clock, 0
	 or	%i0, %lo(res), %i0
	mov	%i5, %o1
	mov	%o0, %o2
	sub	%o0, %i5, %o3
	sethi	%hi(.LC2), %o0
	mov	97, %i1
	or	%o0, %lo(.LC2), %o0
	call	ee_printf, 0
	 mov	97, %i2
	call	print_matrix, 0
	 restore
	.size	main, .-main
	.section	".text"
	.align 4
	.global print_matrix_u8
	.type	print_matrix_u8, #function
	.proc	020
print_matrix_u8:
	save	%sp, -96, %sp
	mov	0, %l0
	cmp	%i1, 0
	ble	.L42
	 mov	0, %l1
	sethi	%hi(.LC0), %i3
	sethi	%hi(.LC1), %l2
	add	%i2, -1, %l3
	or	%i3, %lo(.LC0), %i3
	or	%l2, %lo(.LC1), %l2
	mov	0, %i5
.L40:
	cmp	%i2, 0
	ble	.L32
	 add	%i0, %l1, %i4
	ldub	[%i4+%i5], %o1
.L39:
	call	ee_printf, 0
	 mov	%i3, %o0
	add	%i5, 1, %i5
	cmp	%i5, %i2
	bne,a	.L39
	 ldub	[%i4+%i5], %o1
	add	%l1, 1, %l1
	add	%l1, %l3, %l1
.L32:
	call	ee_printf, 0
	 mov	%l2, %o0
	add	%l0, 1, %l0
	cmp	%l0, %i1
	bne	.L40
	 mov	0, %i5
.L42:
	jmp	%i7+8
	 restore
	.size	print_matrix_u8, .-print_matrix_u8
	.global kernel
	.section	".data"
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
	.global im2col_matrix
	.section	".bss"
	.align 8
	.type	im2col_matrix, #object
	.size	im2col_matrix, 150544
im2col_matrix:
	.skip	150544
	.common	img,10000,8
	.global res
	.align 8
	.type	res, #object
	.size	res, 37636
res:
	.skip	37636
	.ident	"GCC: (Buildroot 2014.08-g538713e-dirty) 4.7.4"
	.section	.note.GNU-stack,"",@progbits
