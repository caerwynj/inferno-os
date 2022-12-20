/*
 * Pico SDK uart 
 */

#include "u.h"
#include "../port/lib.h"
#include "../port/error.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "io.h"
#include "../port/uart.h"
#include "archpico.h"


extern PhysUart picophysuart;

static Uart picouart = {
	.regs	= (u32int*)0,
	.name	= "uart0",
	.freq	= 250000000,
	.phys	= &picophysuart,
};


static Uart*
pnp(void)
{
	Uart *u;

	u = &picouart;
	if(u->console == 0)
		kbdq = qopen(8*1024, 0, nil, nil);
	return u;
}

void
irq_handler(void)
{
	//printf("interrupt\n");
	while (uart_is_readable(uart0)) {
		uchar c;
		c = uart_getc(uart0);
		uartrecv(&picouart, c);
		uart_putc(uart0, c);
	}
}

static void
enable(Uart *uart, int ie)
{
	irq_set_exclusive_handler(UART0_IRQ, irq_handler);
	irq_set_enabled(UART0_IRQ, true);
	uart_set_irq_enables(uart0, true, false);
}

static void
disable(Uart *uart)
{
	irq_set_enabled(UART0_IRQ, 0);
}

static void
kick(Uart *uart)
{}

/* TODO */
static void
dobreak(Uart *uart, int ms)
{
	USED(uart);
	USED(ms);
}

static int
baud(Uart *uart, int n)
{
	if(uart->freq == 0 || n <= 0)
		return -1;
	uart->baud = n;
	return 0;
}

static int
bits(Uart *uart, int n)
{
	uart->bits = n;
	return 0;
}

static int
stop(Uart *uart, int n)
{
	if(n != 1)
		return -1;
	uart->stop = n;
	return 0;
}

static int
parity(Uart *uart, int n)
{
	if(n != 'n')
		return -1;
	uart->parity = n;
	return 0;
}

/*
 * cts/rts flow control
 *   need to bring signals to gpio pins before enabling this
 */

static void
modemctl(Uart *uart, int on)
{}

static void
rts(Uart *uart, int on)
{}

static long
status(Uart *uart, void *buf, long n, long offset)
{
	char *p;

	p = malloc(READSTR);
	if(p == nil)
		error(Enomem);
	snprint(p, READSTR,
		"b%d\n"
		"dev(%d) type(%d) framing(%d) overruns(%d) "
		"berr(%d) serr(%d)\n",

		uart->baud,
		uart->dev,
		uart->type,
		uart->ferr,
		uart->oerr,
		uart->berr,
		uart->serr
	);
	n = readstr(offset, buf, n, p);
	free(p);

	return n;
}

static void
donothing(Uart *uart, int n)
{
}

void
putc(Uart *uart, int c)
{
	uart_putc(uart0, c);
}

int
getc(Uart *uart)
{
	return uart_getc(uart0);
}

void
uartconsinit(void)
{
	Uart *u;
	
	u = &picouart;
	//already initialized by stdio_init_all()
	//uart_init(uart0, 115200);
	//gpio_set_function(0, GPIO_FUNC_UART);
	//gpio_set_function(1, GPIO_FUNC_UART);
	uart_set_hw_flow(uart0, false, false);
	uart_set_fifo_enabled(uart0, false);
	
	if(!u->enabled)
		(*u->phys->enable)(u, 0);
	uartctl(u, "b115200 l8 pn s1");

	consuart = u;
	u->console = 1;
}

PhysUart picophysuart = {
	.name		= "picouart",
	.pnp			= pnp,
	.enable		= enable,
	.disable		= disable,
	.kick			= kick,
	.dobreak		= dobreak,
	.baud		= baud,
	.bits			= bits,
	.stop		= stop,
	.parity		= parity,
	.modemctl	= donothing,
	.rts			= rts,
	.dtr			= donothing,
	.status		= status,
	.fifo			= donothing,
	.getc		= getc,
	.putc		= putc,
};
