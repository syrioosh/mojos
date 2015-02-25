#ifndef __UART_H__
#define __UART_H__
#include "vexpress.h"

struct pl011_uart {
	unsigned long dr;
	unsigned long rsr;
	unsigned long dummy0[4];
	unsigned long fr;
	unsigned long dummy1;
	unsigned long ibrd;
	unsigned long fbrd;
	unsigned long lcr_h;
	unsigned long cr;
	unsigned long imsc;
	unsigned long ris;
	unsigned long mis;
	unsigned long dummy2;
	unsigned long dmacr;
};

void putc(char c);
void puts(const char * str);

#endif

