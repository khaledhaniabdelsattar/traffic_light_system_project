
#include "DIO.h"

void DIO_Init(DIO* cfgparam)
{
	if(cfgparam->UsePullUp == 1)
	{
		SFIOR |= (1<<PUD);
	}
	else
	{
		SFIOR &= (0<<PUD);
	}

	switch(cfgparam->port)
	{
		case 'A':
		if(cfgparam->PortDirection == 1)
		{
			DDRA |= (1<<cfgparam->pin);
		}
		else
		{
			DDRA &= (0<<cfgparam->pin);
		}

		break;

		case 'B':
		if(cfgparam->PortDirection == 1)
		{
			DDRB |= (1<<cfgparam->pin);
		}
		else
		{
			DDRB &= (0<<cfgparam->pin);
		}
		break;

		case 'C':
		if(cfgparam->PortDirection == 1)
		{
			DDRC |= (1<<cfgparam->pin);
		}
		else
		{
			DDRC &= (0<<cfgparam->pin);
		}
		break;

		case 'D':
		if(cfgparam->PortDirection == 1)
		{
			DDRD |= (1<<cfgparam->pin);
		}
		else
		{
			DDRD &= (0<<cfgparam->pin);
		}
		break;
	}
}
void DIO_Writepin(DIO* cfgparam, unsigned char data)
{
	switch(cfgparam->port)
	{
		case 'A':
		if(data == 1)
		{
			PORTA |= (1 << cfgparam->pin);
		}
		else
		{
			PORTA &= (0 << cfgparam->pin);
		}
		break;

		case 'B':
		if(data == 1)
		{
			PORTB |= (1 << cfgparam->pin);
		}
		else
		{
			PORTB &= (0 << cfgparam->pin);
		}
		break;

		case 'C':
		if(data == 1)
		{
			PORTC |= (1 << cfgparam->pin);
		}
		else
		{
			PORTC &= (0 << cfgparam->pin);
		}
		break;

		case 'D':
		if(data == 1)
		{
			PORTD |= (1 << cfgparam->pin);
		}
		else
		{
			PORTD &= (0 << cfgparam->pin);
		}
		break;
	}

}
uint8_t DIO_Readpin(DIO* cfgparam)
{
	switch(cfgparam->port)
	{
		case 'A':
		if(PINA & (1<<cfgparam->pin))
		{
			return ON;
		}
		break;

		case 'B':
		if(PINB & (1<<cfgparam->pin))
		{
			return ON;
		}
		break;

		case 'C':
		if(PINC & (1<<cfgparam->pin))
		{
			return ON;
		}
		break;

		case 'D':
		if(PIND & (1<<cfgparam->pin))
		{
			return ON;
		}
		break;
	}
	return OFF;
}

void DIO_Toggle(DIO* cfgparam)
{
	DIO_Writepin(cfgparam, DIO_Readpin(cfgparam));
}
