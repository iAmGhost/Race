#include "Proximity.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void Proximity_init()
{
	ACSR = 0x80;
}
unsigned int Proximity_getValue()
{
	unsigned int value;

	ADCSRA = 0xC7;

	ADMUX = 0x43;
	ADCSRA = ADCSRA | 0xC7;

	while ((ADCSRA & 0x10) ==0);

	ADCSRA = ADCSRA | 0x10;
	value = (int)ADCL + (int)ADCH * 256;
	ADCSRA = ADCSRA | 0x10;

	return value;
}
