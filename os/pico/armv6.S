	.file	"armv6.S"
#ifndef ARMv7
#define	DMB	mcr     p15, 0, r0, c7, c10, 5
#else
#define	DMB	dmb
#endif


/*
 * ulong _tas(ulong*);
 */
	.align	2
	.global	_tas
	.type	_tas, %function
_tas:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	mov	r3, #1
	mov	r1, r0
	#swp	r0, r3, [r1]
	bx	lr
	.size	_tas, .-_tas


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

FN(islo):
	RET
	
FN(coherence):
	RET


FN(splhi):
	RET
	
FN(spllo):
	RET

FN(splx):
	RET

FN(splxpc):
	RET

FN(setlabel):
	RET
	
FN(gotolabel):
	RET
	
FN(idlehands):
	RET
	
FN(setpanic):
	RET


FN(dumpstack):
	RET
	
