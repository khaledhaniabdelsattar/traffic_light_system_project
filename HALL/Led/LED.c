#include "LED.h"

void LED_Init(DIO *led, uint8_t port_x, uint8_t mask)
{
	led->PortDirection = 1;
	led->UsePullUp = 0;
	led->port = port_x;
	led->pin = mask;
	DIO_Init(led);
}

void LEDON(DIO *led)
{
	DIO_Writepin(led, 1);
}

void LEDOFF(DIO *led)
{
	DIO_Writepin(led, 0);
}

void LEDBlink(DIO *led, int duration_ms)
{
	int periods = duration_ms / 10;

	int i = 0;
	for(i = 0; i < 5; i++)
	{
		LEDON(led);
		delay_ms(periods);
		LEDOFF(led);
		delay_ms(periods);
	}
}
