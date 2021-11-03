#define F_CPU                             16000000UL
#define YouSpinMeRoundRoundBabyRoundRound 1
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "serial.h"
#include "leds.h"
#include "pwmTimer.h"


int main() 
{
    int brightness = 0;
    uart_init(MYBAUD ,0); // setup the uart speed and potential double speed tx/rx for future iteration
    leds_init();
    initPWMTimer();
    int ticktick = 0;

    while(YouSpinMeRoundRoundBabyRoundRound)
    {
        for(brightness = 0; brightness < 255; brightness++)
    {
        setPWMOutput(brightness);
        _delay_ms(4);

    }
      
    for (brightness = 255; brightness > 0; brightness--)
    {
        setPWMOutput(brightness);
        _delay_ms(4);
    }
        /*if (TIFR0 & (1 << OCF0A)) //increment every time the timer raises a flag
        {
			TIFR0 |= (1 << OCF0A); // clears the flag and resets
			if (ticktick == 100) // this gives 1s delay , 100 times it ticks (10ms = 1 tick)
            {
				PORTB ^= (1 << LED_GreenPIN); // toggle 
				ticktick = 0;
			}
				ticktick++; // one tick one cycle	
		}*/
    }
    return 0;
}
