#ifndef __vexpress__
#define __vexpress__

#define MODE_USR        0x10
#define MODE_FIQ        0x11
#define MODE_IRQ        0x12
#define MODE_SVC        0x13
#define MODE_ABT        0x17
#define MODE_UND        0x1B
#define MODE_SYS        0x1F

#define MODE_MASK       0x1F

#define START_ADDRESS 0x60000000

#define UART_BASE    0x10009000

#define GIC_INTERFACE 0x1e000100
#define GIC_DISTRIBUTOR 0x1e000000
#define TIMER_ADDRESS  0x100E4000
#endif
