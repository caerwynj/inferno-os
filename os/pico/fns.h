
#define KADDR(p)	((void *)p)
#define PADDR(p)	((ulong)p)

#define waserror()	(up->nerrlab++, setlabel(&up->errlab[up->nerrlab-1]))
#define procsave(p)	/* Save the mach part of the current */
			/* process state, no need for one cpu */

void    (*screenputs)(char*, int);

#include "../port/portfns.h"

void	archinit(void);
void	coherence(void);
ulong getpc(void);
void poolsizeinit(void);
void setpanic(void);
void idlehands(void);
void clockcheck(void);
void links(void);
uint rom_version(void);
uint clock_sys_freq(void);
void clockinit(void);
uvlong getcpuid(void);
void inferno_panic(const char *, ...);
int printf(const char *, ...);

#define kmapinval()

#define PTR2UINT(p)     ((uintptr)(p))
#define UINT2PTR(i)     ((void*)(i))


#define panic(...)	inferno_panic(__VA_ARGS__)

