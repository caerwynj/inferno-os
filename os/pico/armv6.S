	.file	"armv6.S"
#ifndef ARMv7
#define	DMB	mcr     p15, 0, r0, c7, c10, 5
#else
#define	DMB	dmb
#endif


/*
 *  void		FPsave(void*);
 */
        .align  2
        .global FPsave
        .type   FPsave, %function
FPsave:
        @ args = 0, pretend = 0, frame = 4
        @ frame_needed = 1, uses_anonymous_args = 0
	bx	lr
        .size   FPsave, .-FPsave

/*
 * void		FPrestore(void*);
 */
        .align  2
        .global FPrestore
        .type   FPrestore, %function
FPrestore:
        @ args = 0, pretend = 0, frame = 4
        @ frame_needed = 1, uses_anonymous_args = 0
	bx	lr
        .size   FPrestore, .-FPrestore


#define	FN(x)	.type x,%function; .global x; x
#define	RET	bx lr

FN(setlabel):
	mov r2, r13
	mov r3, r14
	str r2, [r0]
	str r3, [r0, #4]
	mov r0, #0
	RET

FN(gotolabel):
	ldr r2, [r0]
	ldr r3, [r0, #4]
	mov r13, r2
	mov r14, r3
	mov r0, #1
	RET

FN(getpc):
	mov r0, r14
	RET

	
FN(coherence):
	isb
	dsb
	RET
	
FN(spllo):
	cpsie i
	RET

FN(idlehands):
	cpsie i
	wfi
	RET
