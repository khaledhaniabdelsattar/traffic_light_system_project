
#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO/DIO.h"


void Button_Init(DIO *button, uint8_t port_x, uint8_t mask);			// Initialize button
uint8_t ReadButton(DIO *button);										// Read button


#endif /* BUTTON_H_ */
