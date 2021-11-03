#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "leds.h"
#include "serial.h"

void leds_init()    // Function to initialize the leds and put them in a off state
{
    DDRB |= (1<< LED_BluePIN); 
    DDRB |= (1<< LED_GreenPIN);
    DDRB |= (1<< LED_RedPIN);  
    PORTB |= (1 << LED_BluePIN);
    PORTB |= (1 << LED_RedPIN);
    PORTB |= (1 << LED_GreenPIN);
}



