
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"
#include "../Delay/Delay.h"

void LED_Init(DIO *led, uint8_t port_x, uint8_t mask);		// Initialize LED
void LEDON(DIO *led);													// Turn LED on
void LEDOFF(DIO *led);													// Turn LED off
void LEDBlink(DIO *led, int duration_ms);								// Blink LED for a gived duration


#endif /* LED_H_ */
