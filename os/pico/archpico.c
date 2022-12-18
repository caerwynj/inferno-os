#include "u.h"
#include "ureg.h"
#include "archpico.h"
#include "../port/lib.h"
#include "dat.h"
#include "fns.h"
#include <stdatomic.h>
#include "mem.h"


void
archinit(void)
{
	/* initialization for libpico */
	clocks_init();
	stdio_init_all();
}

void
archpicolink(void)
{

}

void
machinit()
{
	m->machno = 0;
	m->ticks = 0;
	m->cpuhz = clock_sys_freq();
	
}


static void
linkproc(void)
{
	spllo();
	if (waserror())
		print("error() underflow: %r\n");
	else (*up->kpfun)(up->arg);
	pexit("end proc", 1);
}

void
kprocchild(Proc *p, void (*func)(void*), void *arg)
{
	p->sched.pc = (ulong)linkproc;
	p->sched.sp = (ulong)p->kstack+KSTACK-8;
	p->kpfun = func;
	p->arg = arg;
}

ulong 
_tas(ulong* lock)
{
	return atomic_flag_test_and_set(lock);
}


int
splhi(void)
{
	ulong pc;
	
	pc = getcallerpc(0);
	m->splpc = pc;
	return save_and_disable_interrupts();
}

void
splx(int status)
{
	ulong pc;
	pc = getcallerpc(0);
	m->splpc = pc;
	restore_interrupts(status);
}

void
splxpc(int status)
{
	int old;
	old = save_and_disable_interrupts();
	restore_interrupts(status);
	//return old;
}

int
islo(void)
{
	return irq_is_enabled(TIMER_IRQ_3);
}

uvlong 
getcpuid(void)
{
	uvlong result = 0;
	int i;
	
	pico_unique_board_id_t id;
	pico_get_unique_board_id(&id);
	
	for (i = 0; i<8; i++)
		result |= id.id[i] << i;
		
	return result;
}


void 
serputs(char *s, int n)
{
	printf("%.*s", n, s);
}

void
microdelay(int us)
{
	sleep_us(us);
}

void
delay(int ms)
{
	sleep_ms(ms);
}

void
clockinit(void)
{
	/* add clockintr to the timer */
}

vlong
clockintr(long alarmid, void *user_data)
{
	Ureg ureg;
	
	ureg.pc = getcallerpc(0);
	timerintr(&ureg, 0);
}


void
timerset(uvlong next)
{
	add_alarm_in_us(next, clockintr, 0, 1);
}

uvlong
fastticks(uvlong *hz)
{
	if(hz)
		*hz = clock_sys_freq();
	return time_us_64();
}

uint
clock_sys_freq()
{
	return clock_get_hz(clk_sys);
}

void reboot(void){}

void 
halt(void )
{
	panic("halt");
}
void fpinit(void) {}
void clockcheck(void) {return; }

void 
segflush(void) { 
	__isb();
	return;
}

void
genrandom(char * buf, int n)
{

}

uint
rom_version(void)
{
	return rp2040_rom_version();
}

void
inferno_panic(const char *fmt, ...)
{
	int n;
	va_list arg;
	char buf[PRINTSIZE];

	setpanic();
	strcpy(buf, "panic: ");
	va_start(arg, fmt);
	n = vseprint(buf+strlen(buf), buf+sizeof(buf)-1, fmt, arg) - buf;
	va_end(arg);
	buf[n] = '\n';
	//dumpstack();

#undef panic
	panic(buf);
	
}

void
setpanic(void)
{
	spllo();
	consoleprint = 1;
}
