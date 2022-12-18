#include <u.h>
#include <kern.h>

/*
 *	Extensions for Inferno to basic libc.h
 */

#define __LITTLE_ENDIAN /* math/dtoa.c */
/* need the inline because the link register is not saved in a known location */
static __inline uintptr getcallerpc(void* dummy) {
	ulong lr;
 	__asm__(	"mov	%0, %%lr;" 
 			: "=r" (lr) 
 	); 
	return lr;
}
