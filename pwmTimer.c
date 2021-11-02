#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "leds.h"


void initTimer()
{
    TCCR0A |= (1 << WGM01);
    TCCR0B |= (1 << CS00) | (1 << CS02);
    OCR0A = 155; // ((CPU_HZ) / ( prescale * hz) -1)    16000000 / (1024 * 100)-1 = 155 
                //                                         15625 / 100 = 156
    TCNT0 = 0; // Counts until OCR0A is reached and then interrupts
}
