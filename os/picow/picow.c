#include "u.h"
#include "../port/lib.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "io.h"
#include "../port/uart.h"
#include "../port/error.h"
#include "interp.h"

#include "picow.root.h"

ulong ndevs = 19;
extern Dev rootdevtab;
extern Dev consdevtab;
extern Dev envdevtab;
extern Dev mntdevtab;
extern Dev pipedevtab;
extern Dev progdevtab;
extern Dev srvdevtab;
extern Dev dupdevtab;
extern Dev uartdevtab;
extern Dev ipdevtab;
extern Dev gpiodevtab;
Dev* devtab[19]={
	&rootdevtab,
	&consdevtab,
	&envdevtab,
	&mntdevtab,
	&pipedevtab,
	&progdevtab,
	&srvdevtab,
	&dupdevtab,
	&uartdevtab,
	&ipdevtab,
	&gpiodevtab,
	nil,
};

extern void archpicolink(void);
extern void ethermediumlink(void);
void links(void){
	archpicolink();
	ethermediumlink();
}

extern void mathmodinit(void);
extern void sysmodinit(void);
void modinit(void){
	mathmodinit();
	sysmodinit();
}

extern PhysUart picophysuart;
PhysUart* physuart[] = {
	&picophysuart,
	nil,
};

#include "../ip/ip.h"
extern void tcpinit(Fs*);
extern void udpinit(Fs*);
extern void ipifcinit(Fs*);
extern void icmpinit(Fs*);
extern void icmp6init(Fs*);
void (*ipprotoinit[])(Fs*) = {
	tcpinit,
	udpinit,
	ipifcinit,
	icmpinit,
	icmp6init,
	nil,
};

	ulong main_pool_pcnt = 75;
	ulong heap_pool_pcnt = 18;
	ulong image_pool_pcnt = 0;
	int cflag = 0;
	int consoleprint = 1;
	int redirectconsole = 1;
	char debug_keys = 1;
	int panicreset = 0;
char* conffile = "picow";
ulong kerndate = KERNDATE;
