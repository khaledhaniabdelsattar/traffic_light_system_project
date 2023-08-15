
#include "Timer.h"

void Timer0_init_normal()
{
	TCCR0 = 0x00;
	TCNT0 = 0x00;
}

void Timer0_start_no_prescalar()
{
	TCCR0 |= (1<<0);
}
