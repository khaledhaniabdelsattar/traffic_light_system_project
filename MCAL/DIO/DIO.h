


#ifndef DIO_H_
#define DIO_H_

#include "../../Registers.h"

// DIO data type
typedef struct
{
	uint8_t PortDirection;
	uint8_t UsePullUp;
	uint8_t port;
	uint8_t pin;
}	DIO;

// Pin state
typedef enum
{
	OFF,
	ON} Pin_states;

void DIO_Init(DIO* cfgparam);									// Initialize GPIO/DIO pin
void DIO_Writepin(DIO* cfgparam, uint8_t data);					// Write on pin
void DIO_Toggle(DIO* cfgparam);									//Toggle Pin
uint8_t DIO_Readpin(DIO* cfgparam);								// Read pin value



#endif /* DIO_H_ */
