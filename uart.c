#include <uart.h>
#include <asm.h>

volatile struct pl011_uart *uart = (struct pl011_uart  *)UART_BASE;

void putc(char c) {
	while(uart->fr & 0x20);
	_write(&uart->dr,c);
	return;
}

void puts(const char * str)
{
	while((*(str)) != '\0') {
		putc((*str++));
	}
}
