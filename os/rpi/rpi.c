#include "u.h"
#include "../port/lib.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "io.h"
#include "../port/uart.h"
#include "../port/error.h"
#include "interp.h"

#include "rpi.root.h"

ulong ndevs = 27;
extern Dev rootdevtab;
extern Dev consdevtab;
extern Dev envdevtab;
extern Dev mntdevtab;
extern Dev pipedevtab;
extern Dev progdevtab;
extern Dev srvdevtab;
extern Dev dupdevtab;
extern Dev uartdevtab;
extern Dev drawdevtab;
extern Dev pointerdevtab;
extern Dev usbdevtab;
extern Dev kbindevtab;
extern Dev sddevtab;
extern Dev ipdevtab;
extern Dev etherdevtab;
extern Dev spidevtab;
extern Dev gpiodevtab;
extern Dev i2cdevtab;
Dev* devtab[27]={
	&rootdevtab,
	&consdevtab,
	&envdevtab,
	&mntdevtab,
	&pipedevtab,
	&progdevtab,
	&srvdevtab,
	&dupdevtab,
	&uartdevtab,
	&drawdevtab,
	&pointerdevtab,
	&usbdevtab,
	&kbindevtab,
	&sddevtab,
	&ipdevtab,
	&etherdevtab,
	&spidevtab,
	&gpiodevtab,
	&i2cdevtab,
	nil,
};

extern void archbcmlink(void);
extern void usbdwclink(void);
extern void etherusblink(void);
extern void ethermediumlink(void);
extern void loopbackmediumlink(void);
void links(void){
	archbcmlink();
	usbdwclink();
	etherusblink();
	ethermediumlink();
	loopbackmediumlink();
}

extern void mathmodinit(void);
extern void sysmodinit(void);
extern void drawmodinit(void);
extern void tkmodinit(void);
extern void keyringmodinit(void);
extern void cryptmodinit(void);
extern void ipintsmodinit(void);
void modinit(void){
	mathmodinit();
	sysmodinit();
	drawmodinit();
	tkmodinit();
	keyringmodinit();
	cryptmodinit();
	ipintsmodinit();
}

#include "../port/sd.h"
extern SDifc sdmmcifc;
SDifc* sdifc[] = {
	&sdmmcifc,
	nil,
};

extern PhysUart miniphysuart;
PhysUart* physuart[] = {
	&miniphysuart,
	nil,
};

#include "../ip/ip.h"
extern void ilinit(Fs*);
extern void tcpinit(Fs*);
extern void udpinit(Fs*);
extern void ipifcinit(Fs*);
extern void icmpinit(Fs*);
extern void icmp6init(Fs*);
void (*ipprotoinit[])(Fs*) = {
	ilinit,
	tcpinit,
	udpinit,
	ipifcinit,
	icmpinit,
	icmp6init,
	nil,
};

	int kernel_pool_pcnt = 10;
	ulong main_pool_pcnt = 40;
	ulong heap_pool_pcnt = 20;
	ulong image_pool_pcnt = 40;
	int cflag = 1;
	int consoleprint = 1;
	int redirectconsole = 1;
	char debug_keys = 1;
	int panicreset = 0;
char* conffile = "rpi";
ulong kerndate = KERNDATE;
