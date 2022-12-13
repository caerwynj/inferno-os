
#define KADDR(p)	((void *)p)
#define PADDR(p)	((ulong)p)

#define waserror()	(up->nerrlab++, setlabel(&up->errlab[up->nerrlab-1]))
#define procsave(p)	/* Save the mach part of the current */
			/* process state, no need for one cpu */

void    (*screenputs)(char*, int);

#include "../port/portfns.h"

void	coherence(void);


#define PTR2UINT(p)     ((uintptr)(p))
#define UINT2PTR(i)     ((void*)(i))

