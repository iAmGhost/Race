#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Devices.h"

void Devices_init()
{
	cli();

	DotMatrix_init();
	DotMatrix_draw();
	UART_init();
	lcdInit();

	DDRB = 0x00;

	_delay_ms(500);

	Proximity_init();
	Joystick_init();

	sei();
}
