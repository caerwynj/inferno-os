#include "u.h"
#include "../port/lib.h"
#include "../port/error.h"
#include "mem.h"
#include	"dat.h"
#include	"fns.h"
#include	<a.out.h>
#include	<dynld.h>

/*
 * null kernel interface to dynld, to stop libinterp moaning
 */

void*
dynimport(Dynobj* d, char* s, ulong n)
{
	return nil;
}

void
dynobjfree(Dynobj* d)
{
}

Dynobj*
kdynloadfd(int fd, Dynsym *tab, int ntab)
{
	USED(fd)
	USED(tab)
	USED(ntab);
	return nil;
}

int
kdynloadable(int n)
{
	return 0;
}

Dynobj*
dynld(int n)
{
	return nil;
}

int
dynldable(int n)
{
	return 0;
}
