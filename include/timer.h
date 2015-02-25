#ifndef TIMER_H
#define TIMER_H

#include <vexpress.h>



enum {
	ONE_SHOT	= 0,
	TIMER_SIZE	= 1,
	TIMER_PRE	= 3,
	TIMER_INTEN	= 5,
	TIMER_MODE	= 6,
	TIMER_EN	= 7
}
timer_control;

struct timer_t {
	unsigned long t1_load;
	unsigned long t1_value;
	unsigned long t1_control;
	unsigned long t1_intclr;
	unsigned long t1_ris;
	unsigned long t1_mis;
	unsigned long t1_bd_load;
};

void timer_init();
void timer1_enable(void);
void timer_enable (volatile struct timer_t *timer);
void timer_irq_enable (volatile struct timer_t *timer);
unsigned int timer1_get_val (void);
unsigned int timer_get_val (volatile struct timer_t *timer);



#endif // TIMER_H
