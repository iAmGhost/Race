#include "Joystick.h"
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned int value = 0;

ISR(TIMER0_OVF_vect)
{
	TCNT0 = 0x00;
	
	ADCSRA = 0xC7;

	ADMUX = 0x00;
	ADCSRA = ADCSRA | 0xC7;

	while ((ADCSRA & 0x10) ==0);

	ADCSRA = ADCSRA | 0x10;
	value = (int)ADCL + (int)ADCH * 256;
	ADCSRA = ADCSRA | 0x10;
}

void Joystick_init()
{
	TCCR0 = 0x05;
	TCNT0 = 0x00;
	TIMSK = TIMSK | 0x1;

	ACSR = 0x80;
}

unsigned int Joystick_getValue()
{
	return value;
}
