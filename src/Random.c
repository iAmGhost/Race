#include "Random.h"
#include <stdlib.h>

void Random_randomize(unsigned int value)
{
	srand(value);
}
