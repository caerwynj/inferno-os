# Map Inferno kernel requirements to libpico and GCC toolchain

Replace taslock with libpico hardware_sync library

No need to initiatlize BSS.  Already done in crt0.S entrypoint.

All hardware peripherals are reset by runtime.c. Clocks are initialized.

We could use _sbrk from libpico/runtime.c to allocate memory.

_tas  - test and set    Use gcc atomic. atomic_flag_test_and_set()  stdatomic.h

tasklock.c:
lock   uses _tas
canlock  uses _tas
unlock  uses _tas
ilock - uses _tas and splhi
iunlock - uses _tas and splxpc

islo - check if irq enable   PRIMASK

splhi - irq disable, store pc in machaddr;   save_and_disable_interrupts(void)

spllx - irq enable;  restore_interrupts(status)

splxpc - 

spllo - enable interrupts.

idlehands - __wfi()

coherence - __isb()

getcpuid - pico_get_unique_board_id()

print - printf()

intrenable -  irq_add_shared_handler()

delay - sleep_ms()

microdelay - sleep_us()

addclock0link - alarm_pool_add_repeating_time_us(), add_repeating_time_us()


Replace trap.c with exception.c and irq.c. Initially the only exception we need
to set might be the timer.

implements clock.c and use libpico timers and clock.
- fastticks, interrupts, perfticks, microdelay.

getcallerpc
/* need the inline because the link register is not saved in a known location */
static __inline uintptr getcallerpc(void* dummy) {
	ulong lr;
 	__asm__(	"mov	%0, %%lr;" 
 			: "=r" (lr) 
 	); 
	return lr;
}


# Networking

Using Cyw43 drvier from pico-sdk.
Not using lwip or the pico_cyw43_driver and it's async context.
Will use inferno ip stack.  Use the etherif.h ether device interface to be used by devip.
ethercyw43.c

