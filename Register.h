
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"
/************************************************************************/
/*							All Registers                               */
/************************************************************************/

/* DIO */
// PORTA Registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

// PORTB Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

// PORTC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)


// PORTD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

// PULLUP
#define SFIOR *((volatile uint8_t*)0x50)

#define PUD 0b00000100

/* Timer */
// Timer0
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)

#define TIFR *((volatile uint8_t*)0x58)

/* Interrupts */
#define GICR *((volatile uint8_t*)0x5B)
#define MCUCR *((volatile uint8_t*)0x55)


#endif /* REGISTERS_H_ */
