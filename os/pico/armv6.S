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
	str r4, [r0, #0]
	str r5, [r0, #4]
	str r6, [r0, #8]
	str r7, [r0, #12]
	mov r1, r8
	str r1, [r0, #16]
	mov r1, r9
	str r1, [r0, #20]
	mov r1, r10
	str r1, [r0, #24]
	mov r1, r11
	str r1, [r0, #28]
	mov r2, r13
	mov r3, r14
	str r2, [r0, #32]
	str r3, [r0, #36]
	mov r0, #0
	RET

FN(gotolabel):
	ldr r4, [r0, #0]
	ldr r5, [r0, #4]
	ldr r6, [r0, #8]
	ldr r7, [r0, #12]
	ldr r1, [r0, #16]
	mov r8, r1
	ldr r1, [r0, #20]
	mov r9, r1
	ldr r1, [r0, #24]
	mov r10, r1
	ldr r1, [r0, #28]
	mov r11, r1
	ldr r2, [r0, #32]
	ldr r3, [r0, #36]
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
	
	
/* Save the mach part of the current proc */
/* TODO this should also call FPsave  */
FN(procsave):
	RET
	
FN(procrestore):
	RET