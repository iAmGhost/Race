#include "UART.h"
#include <avr/io.h>
#include <stdio.h>

void tx0Char(char message)
{
	while (((UCSR0A >> UDRE0) & 0x01) == 0);

	UDR0 = message;
}

int _putchar(char c, FILE *unused)
{
	tx0Char(c);

	return c;
}

int _getchar()
{
	while ((UCSR0A & 0x80) == 0);

	return UDR0;
}

void UART_init()
{
	UCSR0B = 0x00;
	UCSR0A = 0x00;
	UCSR0C = 0x06;

	UBRR0L = 0x67;
	UBRR0H = 0x00;

	UCSR0B = 0x18;

	fdevopen(_putchar, _getchar);
}
