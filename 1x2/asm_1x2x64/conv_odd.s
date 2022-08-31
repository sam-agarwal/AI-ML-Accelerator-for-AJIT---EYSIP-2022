.section ".text"
.align 4
.global conv_odd
.type conv_odd, #function
conv_odd:
	save %sp, -120, %sp
	! %i0 is image ptr
	! %i1 is 16
	! %i2 is n
	! %i3 is kernel ptr
	! %i4 is result ptr

	set 0xFF, %i5		! mask for adddreduce8
	set 1, %g2
	set 1, %g3
	set 3, %o2
	set 3, %o3

	ldd [%i3],   %l0	! l0 - l3 hold the kernel values (16 8bit elements in total)
	ldd [%i3+8], %l2 
	
	umul %i2, 2, %o0
	add %i0, %o0, %i1       ! i1 is having ptr of the lower half of the sliding window of image
	
	clr %o0 		!o0 is used as x counter
	clr %o1			!o1 is used as y counter

	sub %i2, 3, %g4		! g4 has the index till where sliding has to take place
	!clr %l4
	!clr %l5
	
	set -1, %o1
	

	ld [%i0], %l4
load1:	add %i0, %i2, %o5
	ld [%o5], %l5
	ld [%i1], %l6
	add %i1, %i2, %o5
	ld [%o5], %l7
	
	
	ba comp
	vaddd32 %i0, %o2, %i0


load2: 	sll %l4, 8, %l4
	sll %l5, 8, %l5
	sll %l6, 8, %l6
	sll %l7, 8, %l7
	ldub [%i0], %o4
	add %l4, %o4, %l4
	add %i0, %i2, %o5
	ldub [%o5], %o4			
	add %l5, %o4, %l5
	ldub [%i1], %o4
	add %l6, %o4, %l6
	add %i1, %i2, %o5
	ldub [%o5], %o4
	add %l7, %o4, %l7

comp:	vumuld8 %l0, %l4, %o4		! l4-l7 has dot product result 
	adddreduce8 %o4, %i5, %o4
	clr %g1
	add %o4, %g1, %g1
	vumuld8 %l2, %l6, %o4
	adddreduce8 %o4, %i5, %o4
	add %o4, %g1, %g1		! g1 has result of one convolution

	st %g1, [%i4]
	add %i4, 4, %i4			! result ptr updated here	

	inc %o0
	cmp %o0,%g4
	bne load2			! if the x ptr is not equal to ending ptr, go to load. if equal, we have to update the ptr differently
	vaddd32 %g2, %i0, %i0   	! the image ptrs are updated

	clr %o0
	add %o1,2, %o1				! increase the y ptr 2 times
	
	
	add %i0, %i2, %i0	! increase the image ptr by n as to shift the pointer to next line
	add %i1, %i2, %i1 
	
	umul %g4, 4, %g4
	add %i4, %g4, %i4
	sub %i2, 3, %g4

	sub %g4, 1, %g4		! calculating n-4

	cmp %o1, %g4

	bge finish
	inc %g4

	ba load1
	ld [%i0], %l4	
	
finish:	ret
	restore
