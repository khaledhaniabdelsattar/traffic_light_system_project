#define F_CPU 1000000U


#include "Registers.h"
#include "App.h"
#include <avr/interrupt.h>


// Interrupt
ISR(INT0_vect)
{
	pedisterian_mode = 1;
}

int main(void)
{
    // Initializing interrupt
	GICR = 1<<INT0;
	MCUCR = 1<<ISC01 | 1<<ISC00;

	sei();

	App_start();
}
