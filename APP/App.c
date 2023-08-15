#include "App.h"

int pedisterian_mode = 0;
DIO cars[3];
DIO pedisterian[3];

// Pedestrian Mode
void ped()
{
	if((pedisterian_mode == 1) && (DIO_Readpin(&cars[2]) == OFF))
	{
		int i = 0;


		for(i = 0; i < 3; i++)
		{
			if(i == 1)
			{
				yellow_blink();
				continue;
			}
			LEDON(&pedisterian[i]);
			LEDON(&cars[2-i]);
			delay_ms(5000);
			LEDOFF(&pedisterian[i]);
			LEDOFF(&cars[2-i]);
		}
		yellow_blink();

		pedisterian_mode = 0;
	}

}

// Blinking two yellow  leds on the same time
void yellow_blink()
{
	int periods = 5000 / 10;			// Blink duty cycle

	int i = 0;
	for(i = 0; i < 5; i++)
	{
		LEDON(&cars[1]);
		LEDON(&pedisterian[1]);
		delay_ms(periods);
		LEDOFF(&cars[1]);
		LEDOFF(&pedisterian[1]);
		delay_ms(periods);
	}
}

void App_start()
{
	// Initializing button
	DIO int0;
	Button_Init(&int0, 'D', 2);


	// Initializing LEDs
	int i = 0;
	int mask_cars = 0;
	int mask_ped = 0;
	for(i = 0; i < 3; i++)
	{
		LED_Init(&cars[i], 'B', mask_cars);
		mask_cars++;
	}

	for(i = 0; i < 3; i++)
	{
		LED_Init(&pedisterian[i], 'A', mask_ped);
		mask_ped++;
	}

	while (1)
	{
		// Cars mode
		int i = 0;
		for(i = 0; i < 3; i++)
		{
			if(i == 1)
			{
				yellow_blink();			// Blinking both yellow LEDs
				if(pedisterian_mode == 1)
				{
					ped();
				}
				continue;
			}
			// Turning green and red LEDs on and off
			LEDON(&cars[i]);
			LEDON(&pedisterian[2-i]);
			delay_s(5);
			LEDOFF(&cars[i]);
			LEDOFF(&pedisterian[2-i]);
		}

		yellow_blink();					// Blinking both yellow LEDs
	}
}
