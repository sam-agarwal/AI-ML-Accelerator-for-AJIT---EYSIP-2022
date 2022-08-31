	.file	"serial_1.c"
	.section	".text"
	.align 4
	.global __ajit_write_serial_1_control_register_via_vmap__
	.type	__ajit_write_serial_1_control_register_via_vmap__, #function
	.proc	020
__ajit_write_serial_1_control_register_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 576, %g1
	jmp	%o7+8
	 st	%o0, [%g1]
	.size	__ajit_write_serial_1_control_register_via_vmap__, .-__ajit_write_serial_1_control_register_via_vmap__
	.align 4
	.global __ajit_read_serial_1_control_register_via_vmap__
	.type	__ajit_read_serial_1_control_register_via_vmap__, #function
	.proc	016
__ajit_read_serial_1_control_register_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 576, %g1
	jmp	%o7+8
	 ldub	[%g1], %o0
	.size	__ajit_read_serial_1_control_register_via_vmap__, .-__ajit_read_serial_1_control_register_via_vmap__
	.align 4
	.global __ajit_write_serial_1_tx_register_via_vmap__
	.type	__ajit_write_serial_1_tx_register_via_vmap__, #function
	.proc	020
__ajit_write_serial_1_tx_register_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 580, %g1
	jmp	%o7+8
	 stb	%o0, [%g1]
	.size	__ajit_write_serial_1_tx_register_via_vmap__, .-__ajit_write_serial_1_tx_register_via_vmap__
	.align 4
	.global __ajit_read_serial_1_tx_register_via_vmap__
	.type	__ajit_read_serial_1_tx_register_via_vmap__, #function
	.proc	014
__ajit_read_serial_1_tx_register_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 580, %g1
	jmp	%o7+8
	 ldub	[%g1], %o0
	.size	__ajit_read_serial_1_tx_register_via_vmap__, .-__ajit_read_serial_1_tx_register_via_vmap__
	.align 4
	.global __ajit_read_serial_1_rx_register_via_vmap__
	.type	__ajit_read_serial_1_rx_register_via_vmap__, #function
	.proc	014
__ajit_read_serial_1_rx_register_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 584, %g1
	jmp	%o7+8
	 ldub	[%g1], %o0
	.size	__ajit_read_serial_1_rx_register_via_vmap__, .-__ajit_read_serial_1_rx_register_via_vmap__
	.align 4
	.global __ajit_serial_1_putchar_via_vmap__
	.type	__ajit_serial_1_putchar_via_vmap__, #function
	.proc	04
__ajit_serial_1_putchar_via_vmap__:
	sethi	%hi(-53248), %g2
	or	%g2, 576, %g1
	ld	[%g1], %g1
	andcc	%g1, 1, %g0
	be	.L7
	 mov	0, %g3
	andcc	%g1, 8, %g0
	bne	.L7
	 or	%g2, 580, %g2
	mov	%o0, %g3
	stb	%o0, [%g2]
.L7:
	jmp	%o7+8
	 mov	%g3, %o0
	.size	__ajit_serial_1_putchar_via_vmap__, .-__ajit_serial_1_putchar_via_vmap__
	.align 4
	.global __ajit_serial_1_getchar_via_vmap__
	.type	__ajit_serial_1_getchar_via_vmap__, #function
	.proc	04
__ajit_serial_1_getchar_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 576, %g2
	ld	[%g2], %g2
	and	%g2, 18, %g2
	cmp	%g2, 18
	bne	.L15
	 mov	0, %o0
	or	%g1, 584, %g1
	ldub	[%g1], %o0
.L15:
	jmp	%o7+8
	 nop
	.size	__ajit_serial_1_getchar_via_vmap__, .-__ajit_serial_1_getchar_via_vmap__
	.align 4
	.global __ajit_serial_1_puts_via_vmap__
	.type	__ajit_serial_1_puts_via_vmap__, #function
	.proc	020
__ajit_serial_1_puts_via_vmap__:
	sethi	%hi(-53248), %o3
	mov	0, %o5
	or	%o3, 576, %o4
	mov	0, %g4
	cmp	%o1, 0
	be	.L34
	 or	%o3, 580, %o3
.L29:
	ld	[%o4], %g1
.L32:
	ldub	[%o0+%o5], %g3
	and	%g1, 1, %g2
	and	%g1, 8, %g1
	cmp	%g2, 0
.L31:
	bne	.L22
	 cmp	%g1, 0
.L19:
	b,a	.L19
.L22:
	bne	.L31
	 cmp	%g2, 0
	stb	%g3, [%o3]
	sll	%g3, 24, %g3
	cmp	%g3, 0
	be,a	.L32
	 ld	[%o4], %g1
	add	%g4, 1, %g4
	cmp	%g4, %o1
	bne	.L29
	 mov	%g4, %o5
.L34:
	jmp	%o7+8
	 nop
	.size	__ajit_serial_1_puts_via_vmap__, .-__ajit_serial_1_puts_via_vmap__
	.align 4
	.global __ajit_serial_1_gets_via_vmap__
	.type	__ajit_serial_1_gets_via_vmap__, #function
	.proc	020
__ajit_serial_1_gets_via_vmap__:
	sethi	%hi(-53248), %o5
	mov	0, %o4
	or	%o5, 576, %g4
	mov	0, %g3
	cmp	%o1, 0
	be	.L53
	 or	%o5, 584, %o5
.L48:
	ld	[%g4], %g1
.L51:
	andcc	%g1, 2, %g0
	be	.L39
	 and	%g1, 16, %g2
	cmp	%g2, 0
	bne,a	.L40
	 ldub	[%o5], %g1
.L41:
	b,a	.L41
.L39:
	b,a	.L39
.L40:
	cmp	%g1, 0
	be,a	.L51
	 ld	[%g4], %g1
	stb	%g1, [%o0+%o4]
	add	%g3, 1, %g3
	cmp	%g3, %o1
	bne	.L48
	 mov	%g3, %o4
.L53:
	jmp	%o7+8
	 nop
	.size	__ajit_serial_1_gets_via_vmap__, .-__ajit_serial_1_gets_via_vmap__
	.align 4
	.global __ajit_serial_1_configure_via_vmap__
	.type	__ajit_serial_1_configure_via_vmap__, #function
	.proc	020
__ajit_serial_1_configure_via_vmap__:
	sethi	%hi(-53248), %g1
	or	%g1, 576, %g1
	cmp	%o0, 0
	ld	[%g1], %g2
	be	.L56
	 and	%g2, -2, %g1
	or	%g2, 1, %g1
.L56:
	cmp	%o1, 0
	be	.L58
	 and	%g1, -3, %g2
	or	%g1, 2, %g2
.L58:
	cmp	%o2, 0
	be	.L60
	 and	%g2, -5, %g1
	or	%g2, 4, %g1
.L60:
	sethi	%hi(-53248), %g2
	or	%g2, 576, %g2
	jmp	%o7+8
	 st	%g1, [%g2]
	.size	__ajit_serial_1_configure_via_vmap__, .-__ajit_serial_1_configure_via_vmap__
	.ident	"GCC: (Buildroot 2014.08-g538713e-dirty) 4.7.4"
	.section	.note.GNU-stack,"",@progbits
