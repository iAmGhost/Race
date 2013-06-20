#include "DotMatrix.h"
#define EX_DM_SEL (*(volatile unsigned int *)0x8004)
#define EX_DM_DATA (*(volatile unsigned int *)0x8006)
#define RANGE_CHECK(X, Y) (!((X) < 0 || (X) >= 10 || (Y) >= 10 || (Y) < 0))

int dmi = 0;

int buffer[10] = {0x00, };

void DotMatrix_init()
{
	MCUCR = 0x80;
}

void DotMatrix_drawPixel(int x, int y)
{
	if (!RANGE_CHECK(x,y))
	{
		return;
	}

	buffer[y] = buffer[y] | (1 << (9-x));
}

void DotMatrix_removePixel(int x, int y)
{
	if (!RANGE_CHECK(x,y))
	{
		return;
	}

	buffer[y] = buffer[y] & ~(1 << (9-x));
}

void DotMatrix_draw()
{
	EX_DM_SEL = (1 << dmi);
	EX_DM_DATA = buffer[dmi];

	dmi++;

	if (dmi > 9)
	{
		dmi = 0;
	}
}

void DotMatrix_reset()
{
	EX_DM_SEL = 0b1111111111;
	EX_DM_DATA = 0;
}

void DotMatrix_clear()
{
	memset(buffer, 0, sizeof(buffer));
}

