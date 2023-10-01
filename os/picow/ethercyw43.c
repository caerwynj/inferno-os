/* Cyw43 Driver */

#include "u.h"
#include "../port/lib.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "io.h"
#include "../port/error.h"
#include "../port/netif.h"
#include "etherif.h"
#include "cyw43.h"

struct Ctrl 
{
	Lock l;

	
};

extern cyw43_t cyw43_state;

static void
multicast(void*, uchar*, int)
{
	// BUG: to be added.
}

static void
attach(Ether* ether)
{
}

static long
ifstat(Ether* ether, void* a, long n, ulong offset)
{
	return 0;
}

static long
ctl(Ether* ether, void* buf, long n)
{

	return 0;
}

static void
transmit(Ether* ether)
{
}


static void
promiscuous(void* arg, int on)
{
}


static void
interrupt(Ureg* ,void* arg)
{

}

static int
reset(Ether *ether)
{

	ether->attach = attach;
	ether->interrupt = interrupt;
	ether->transmit = transmit;
	ether->ifstat = ifstat;
	ether->ctl = ctl;
	ether->promiscuous = promiscuous;
	ether->multicast = multicast;
	ether->arg = ether;

	return 0;
}
	
void
etherwavelanlink(void)
{
	addethercard("cyw43", reset);
}
