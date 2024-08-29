#include "u.h"
#include "ureg.h"
#include "archpico.h"
#include "../port/lib.h"
#include "dat.h"
#include "fns.h"
#include <stdatomic.h>
#include "mem.h"


static spin_lock_t *hw_lock;
static alarm_pool_t *alarm_pool;

void
archinit(void)
{
	/* initialization for libpico */
	clocks_init();
	stdio_init_all();
	hw_lock = spin_lock_init(PICO_SPINLOCK_ID_OS1);
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
	/* there is no synchronization primitive on Arm6-M architecture.
	 * try RP2040 hardware spin lock; init a global spin_lock_t first.
	 * spin_lock_unsafe_blocking() 
	 * test and set lock
	 * spin_unlock_unsafe()
	 */

	ulong l;
	spin_lock_unsafe_blocking(hw_lock);
	l = atomic_flag_test_and_set(lock);
	spin_unlock_unsafe(hw_lock);
	return l;
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

vlong
clockintr(long alarmid)
{
	Ureg ureg;
	
	ureg.pc = getcallerpc(0);
	timersettick();
	timerintr(&ureg, 0);
}

void
clockinit(void)
{
	/* add clockintr to the timer*/
	hardware_alarm_claim(1);
	hardware_alarm_set_callback(1, clockintr);
	timersettick();
}

void
timerset(uvlong next)
{
	USED(next);
}

void
timersettick()
{
	int r;
	absolute_time_t t;

	r = hardware_alarm_set_target(1, delayed_by_us(get_absolute_time(), 10000));
	if(r == 1){
		print("alarm target missed\n");
		r = hardware_alarm_set_target(1, delayed_by_us(get_absolute_time(), 100000));
		if(r == 1)
			print("alarm missed again\n");
	}
}

uvlong
fastticks(uvlong *hz)
{

	if(hz)
		*hz =  clock_sys_freq(); 
	return time_us_64();
}

uint
clock_sys_freq()
{
	return 4000000;  /*clock_get_hz(clk_ref); */
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
__wrap_panic(const char *fmt, ...)
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

	__real_panic(buf);
	
}

void
setpanic(void)
{
	spllo();
	consoleprint = 1;
}
