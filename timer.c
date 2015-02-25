#include <vexpress.h>
#include <timer.h>
#include <uart.h>
#include <util.h>
#include <interrupt.h>

volatile struct timer_t * timer  = (struct timer_t *)TIMER_ADDRESS;

void timer_enable (volatile struct timer_t *timer) 
{
	timer->t1_load = 0xFFFFF;
	timer->t1_bd_load = 0xFFFFF;
	timer->t1_control = timer->t1_control | (0 << TIMER_PRE) | (1 << TIMER_SIZE) | ( 1<< TIMER_EN) | (1 << TIMER_MODE);
	
	timer_irq_enable(timer);
	
}


void timer_irq_enable (volatile struct timer_t *timer) 
{
	gic_icidser(0x80);
	gic_icdiptr(0x80,0);
	*((unsigned long *)(GIC_INTERFACE + ICCPMR)) = 0xFFFF;
	*((unsigned long *)(GIC_INTERFACE + ICCICR)) = 1;
	*((unsigned long *)(GIC_INTERFACE + ICDDCR)) = 1;
}

void timer1_enable(void)
{
	timer_enable(timer);
}

unsigned int timer1_get_val (void)
{
	return timer_get_val(timer);
}

unsigned int timer_get_val (volatile struct timer_t *timer) 
{
	return timer->t1_value;
}

void timer1_irq_enable(void) 
{
	return timer_irq_enable(timer);
}


