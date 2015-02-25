#include <asm.h>
void switch_mode(int mode) {
	register unsigned long tmp = 0;

	mode &= ~MODE_MASK;

	asm volatile(
		"mrs %[tmp], cpsr_all \n"
		"bic %[tmp], %[tmp], %[mask] \n"
		"orr %[tmp], %[tmp], %[mode] \n"
		"msr cpsr_all, %[tmp] \n"
		: : [mode] "r" (mode), [mask] "I" (MODE_MASK), [tmp] "r" (tmp)
	);
}

unsigned long get_cpsr();

void print_curr_mode() {

}