#include "Button.h"

void Button_Init(DIO *button, uint8_t port_x, uint8_t mask)
{
	button->PortDirection = 0;
	button->UsePullUp = 0;
	button->port = port_x;
	button->pin = mask;
	DIO_Init(button);
}

uint8_t ReadButton(DIO *button)
{
	return DIO_Readpin(button);
}
