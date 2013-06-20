#include "Road.h"
#include "Macro.h"
#include "DotMatrix.h"
#include "Settings.h"

int Road_time = 0;
int Road_status = 0;

void Road_draw(Entity *entity)
{
	int i;

	for (i = -4; i < 13; i += 3)
	{
		DotMatrix_drawPixel(0, i + Road_status);
		DotMatrix_drawPixel(0, i + Road_status + 1);
		DotMatrix_drawPixel(9, i + Road_status);
		DotMatrix_drawPixel(9, i + Road_status + 1);
	}
}

void Road_think(Entity *entity)
{
	if (Road_time > Settings_getGameSpeed())
	{
		Road_status++;

		if (Road_status >= 3)
		{
			Road_status = 0;
		}

		Road_time = 0;
	}

	Road_time++;
}

Entity* Road_create()
{
	Entity *entity = Entity_create();
	
	entity->type = ENTITY_ROAD;
	entity->width = 10;
	entity->height = 10;
	entity->draw = Road_draw;
	entity->think = Road_think;

	return entity;
}
