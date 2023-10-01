#include "u.h"
#include "../port/lib.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "../port/error.h"

#include "ip.h"

static void
nullbind(Ipifc* ipc, int n, char** s)
{
	error("cannot bind null device");
}

static void
nullunbind(Ipifc* ifc)
{
}

static void
nullbwrite(Ipifc* ifc, Block* b, int n, uchar* s)
{
	error("nullbwrite");
}

Medium nullmedium =
{
.name=		"null",
.bind=		nullbind,
.unbind=	nullunbind,
.bwrite=	nullbwrite,
};

void
nullmediumlink(void)
{
	addipmedium(&nullmedium);
}
