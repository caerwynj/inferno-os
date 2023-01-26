#include "u.h"
#include "../port/lib.h"
#include "dat.h"
#include "mem.h"
#include "fns.h"
#include "version.h"
#include "archpico.h"


Mach machaddr;
Conf conf;
Mach *m;
Proc *up = 0;

extern int main_pool_pcnt;
extern int heap_pool_pcnt;
extern int image_pool_pcnt;
extern char __StackLimit[];
extern char __StackTop[];
extern char __HeapLimit[];
extern char __bss_start__[];
extern char __bss_end__[];
extern char __data_end__[];

extern void serputs(char*, int);

int main() {
	char a[1];
	int n;
	
	m = &machaddr;
	machinit();
	
	archinit();
	serwrite = serputs;
	screenputs = 0;
	printf("Hello, inferno!\n");
	
	conf.nmach = 1;

	printf("stack %x  pc  %x  main  %x\n", &n, getcallerpc(main), main);
	printf("sp %x  pc %x,   end %x\n", a,  getpc(), end); 
	printf("stacklimit %x, heaplimit %x, stacktop %x\n", __StackLimit, __HeapLimit, __StackTop);
	printf("bss_start %x, bss_end%x\n",__bss_start__, __bss_end__);
	printf("edata %x, end-edata %d\n", __data_end__, end-__data_end__);
	
	quotefmtinstall();
	confinit();
	xinit();
	
	
	printf("Conf: base0=%x, npage0=%x, ialloc=%d, nproc=%d\n",
			conf.base0, conf.npage0,
			conf.ialloc, conf.nproc);
	poolinit();
	poolsizeinit();
	uartconsinit();
	//screeninit();
	//trapinit();
	timersinit();
	clockinit();
	printinit();
	//swcursorinit();
	
	print("\nARM %ld MHz id %8.8lux firmware: rev %d, mem: %ld\n"
		,m->cpuhz/Mhz, getcpuid(), rom_version(), (conf.topofmem - KZERO));

	print("Inferno OS %s Vita Nuova\n", VERSION);
	print("Ported to Raspberry Pi Pico (RP2040) by Caerwyn Jones\n\n");

	procinit();
	links();
	chandevreset();

	eve = strdup("inferno");

	userinit();
	schedinit();
	
	while (true) {
		print("Hello, world!\n");
		sleep_ms(1000);
	}
	return 0;
}


void
confinit(void)
{
	ulong base;
	conf.topofmem = (ulong)__StackLimit;

	base = PGROUND((ulong)end);
	conf.base0 = base;

	conf.npage1 = 0;
	conf.npage0 = (conf.topofmem - base)/BY2PG;
	conf.npage = conf.npage0 + conf.npage1;
	conf.ialloc = (((conf.npage*(main_pool_pcnt))/100)/2)*BY2PG;

	conf.nproc = 5 + ((conf.npage*BY2PG)/MB)*5;
	conf.nmach = 1;

	active.machs = 1;
	active.exiting = 0;

	printf("Conf: top=%x, npage0=%d, ialloc=%d, nproc=%d\n",
			conf.topofmem, conf.npage0,
			conf.ialloc, conf.nproc);
}

void
poolsizeinit(void)
{
	ulong nb;

	nb = conf.npage*BY2PG;
	poolsize(mainmem, (nb*main_pool_pcnt)/100, 0);
	poolsize(heapmem, (nb*heap_pool_pcnt)/100, 0);
	poolsize(imagmem, (nb*image_pool_pcnt)/100, 1);
}


void
init0(void)
{
	Osenv *o;
	char buf[2*KNAMELEN];

	up->nerrlab = 0;

	print("Starting init0()\n");
	spllo();

	if(waserror())
		panic("init0 %r");

	/* These are o.k. because rootinit is null.
	 * Then early kproc's will have a root and dot. */

	o = up->env;
	o->pgrp->slash = namec("#/", Atodir, 0, 0);
	cnameclose(o->pgrp->slash->name);
	o->pgrp->slash->name = newcname("/");
	o->pgrp->dot = cclone(o->pgrp->slash);

	chandevinit();

	if(!waserror()){
		ksetenv("cputype", "arm", 0);
		snprint(buf, sizeof(buf), "arm %s", conffile);
		ksetenv("terminal", buf, 0);
		//snprint(buf, sizeof(buf), "%s", getethermac());
		//ksetenv("ethermac", buf, 0);
		poperror();
	}

	poperror();

	disinit("/osinit.dis");
}

void
userinit(void)
{
	Proc *p;
	Osenv *o;

	p = newproc();
	o = p->env;

	o->fgrp = newfgrp(nil);
	o->pgrp = newpgrp();
	o->egrp = newegrp();
	kstrdup(&o->user, eve);

	strcpy(p->text, "interp");

	p->fpstate = FPINIT;

	/*	Kernel Stack
		N.B. The -12 for the stack pointer is important.
		4 bytes for gotolabel's return PC */
	p->sched.pc = (ulong)init0;
	p->sched.sp = (ulong)p->kstack+KSTACK-8;

	ready(p);
}

