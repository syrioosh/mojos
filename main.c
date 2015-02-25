#include <asm.h>
#include <vexpress.h>
#include <uart.h>
#include <timer.h>
#include <interrupt.h>

#define cpu_enable_irq() __asm__ __volatile__("cpsie i" : : : "memory", "cc")




int main() {
	
	putc('t');
	putc('e');
	putc('s');
	putc('t');
	putc('\n');
	putc('\r');

	unsigned int val = 0;
	timer1_enable();
	cpu_enable_irq();
	for(;;) {
		val = timer1_get_val();
		if (val == 0) {
			puts("A\n");
		}
	}

	return 0;
}
