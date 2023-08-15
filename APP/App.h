#ifndef APP_H_
#define APP_H_

// Drivers
#include "ECUAL/LED/LED.h"
#include "ECUAL/Button/Button.h"
#include "ECUAL/Delay/Delay.h"

extern int pedisterian_mode;


void ped();
void yellow_blink();

void App_start();


#endif /* APP_H_ */
