#include "Delay.h"

void delay_s(double s)
{
	Timer0_init_normal();
	Timer0_start_no_prescalar();

	double tick = 1.0 / (F_CPU);
	double max_delay = tick * 256;

	int N = (s / max_delay);;
	int counter = 0;

	while(counter < N)
	{
		while((TIFR & (1<<0)) == 0);

		TIFR |= (1 << 0);
		counter++;
	}
	TCCR0 = 0x00;
}

void delay_ms(double ms)
{
	double T = ms / 1000;

	delay_s(T);
}
