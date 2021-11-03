#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "leds.h"

void initPWMTimer()
{
    TCCR2A |= (1 << WGM20) | (1 << WGM21) | (1 << COM2A1);//NonInvert mode and fast pwm active
    TCCR2B |= (1 << CS20) | (1 << CS21);

}

int interruptCalculator(int mhz, int prescale, int interruptMs)
{
    return interruptMs*1000/16;
}


void setPWMOutput(int duty)
{
    OCR2A = duty;
}