	.file	"ajit_generic_sys_calls.c"
	.section	".text"
	.align 4
	.global ajit_sys_get_core_and_thread_id
	.type	ajit_sys_get_core_and_thread_id, #function
	.proc	020
ajit_sys_get_core_and_thread_id:
	save	%sp, -96, %sp
	call	ajit_sys_read_asr, 0
	 mov	29, %o0
	srl	%o0, 8, %g1
	stb	%g1, [%i0]
	stb	%o0, [%i1]
	jmp	%i7+8
	 restore
	.size	ajit_sys_get_core_and_thread_id, .-ajit_sys_get_core_and_thread_id
	.align 4
	.global ajit_sys_get_clock_time
	.type	ajit_sys_get_clock_time, #function
	.proc	017
ajit_sys_get_clock_time:
	save	%sp, -96, %sp
	call	ajit_sys_read_asr, 0
	 mov	30, %o0
	mov	%o0, %i4
	call	ajit_sys_read_asr, 0
	 mov	31, %o0
	mov	%i4, %i5
	mov	0, %g3
	mov	0, %i4
	or	%g3, %i5, %g3
	or	%o0, %i4, %g2
	mov	%g3, %i1
	jmp	%i7+8
	 restore %g0, %g2, %o0
	.size	ajit_sys_get_clock_time, .-ajit_sys_get_clock_time
	.align 4
	.global ajit_sys_sleep
	.type	ajit_sys_sleep, #function
	.proc	020
ajit_sys_sleep:
	save	%sp, -96, %sp
	call	ajit_sys_read_asr, 0
	 mov	30, %o0
	mov	%o0, %i2
	call	ajit_sys_read_asr, 0
	 mov	31, %o0
	mov	%i2, %i3
	mov	0, %g3
	or	%g3, %i3, %g3
	addcc	%g3, %i0, %i1
	mov	0, %i2
	or	%o0, %i2, %g2
	addx	%g2, 0, %i0
	cmp	%i0, %g2
	bleu	.L14
	 nop
.L11:
	call	ajit_sys_read_asr, 0
	 mov	30, %o0
	mov	%o0, %i3
	call	ajit_sys_read_asr, 0
	 mov	31, %o0
	mov	0, %i5
	mov	%o0, %i4
	mov	0, %o0
	or	%i4, %o0, %o0
	cmp	%i0, %o0
	bgu	.L11
	 or	%i5, %i3, %o1
	cmp	%i0, %o0
	bne	.L16
	 cmp	%i1, %o1
	bgu	.L11
	 nop
.L16:
	jmp	%i7+8
	 restore
.L14:
	bne	.L16
	 cmp	%i1, %g3
	bgu	.L11
	 nop
	jmp	%i7+8
	 restore
	.size	ajit_sys_sleep, .-ajit_sys_sleep
	.ident	"GCC: (Buildroot 2014.08-g538713e-dirty) 4.7.4"
	.section	.note.GNU-stack,"",@progbits
