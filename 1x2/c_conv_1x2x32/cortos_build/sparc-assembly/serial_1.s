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
	sethi	%hi(-53248), %o4
	mov	0, %g4
	or	%o4, 576, %o5
	mov	0, %g3
	cmp	%o1, 0
	be	.L36
	 or	%o4, 580, %o4
.L29:
	ld	[%o5], %g2
.L34:
	andcc	%g2, 1, %g0
	bne	.L32
	 ldub	[%o0+%g4], %g1
.L19:
	b,a	.L19
.L32:
	and	%g2, 8, %g2
	cmp	%g2, 0
.L33:
	bne	.L33
	 nop
	stb	%g1, [%o4]
	sll	%g1, 24, %g1
	cmp	%g1, 0
	be,a	.L34
	 ld	[%o5], %g2
	add	%g3, 1, %g3
	cmp	%g3, %o1
	bne	.L29
	 mov	%g3, %g4
.L36:
	jmp	%o7+8
	 nop
	.size	__ajit_serial_1_puts_via_vmap__, .-__ajit_serial_1_puts_via_vmap__
	.align 4
	.global __ajit_serial_1_gets_via_vmap__
	.type	__ajit_serial_1_gets_via_vmap__, #function
	.proc	020
__ajit_serial_1_gets_via_vmap__:
	sethi	%hi(-53248), %g4
	mov	0, %o5
	or	%g4, 576, %g3
	mov	0, %g2
	cmp	%o1, 0
	be	.L60
	 or	%g4, 584, %g4
.L51:
	ld	[%g3], %g1
.L58:
	andcc	%g1, 2, %g0
	bne	.L56
	 andcc	%g1, 16, %g0
.L42:
	b,a	.L42
.L56:
	bne,a	.L57
	 ldub	[%g4], %g1
.L52:
	b,a	.L52
.L57:
	cmp	%g1, 0
	be,a	.L58
	 ld	[%g3], %g1
	stb	%g1, [%o0+%o5]
	add	%g2, 1, %g2
	cmp	%g2, %o1
	bne	.L51
	 mov	%g2, %o5
.L60:
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
	be	.L63
	 and	%g2, -2, %g1
	or	%g2, 1, %g1
.L63:
	cmp	%o1, 0
	be	.L65
	 and	%g1, -3, %g2
	or	%g1, 2, %g2
.L65:
	cmp	%o2, 0
	be	.L67
	 and	%g2, -5, %g1
	or	%g2, 4, %g1
.L67:
	sethi	%hi(-53248), %g2
	or	%g2, 576, %g2
	jmp	%o7+8
	 st	%g1, [%g2]
	.size	__ajit_serial_1_configure_via_vmap__, .-__ajit_serial_1_configure_via_vmap__
	.ident	"GCC: (Buildroot 2014.08) 4.7.4"
	.section	.note.GNU-stack,"",@progbits
