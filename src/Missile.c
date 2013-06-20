#include "Missile.h"
#include "DotMatrix.h"

int Missile_time = 0;

void Missile_think(Entity *entity)
{
	if (entity->y < 0 && PINB)
	{
		entity->enabled = FALSE;
	}
	else
	{
		entity->enabled = TRUE;

		if (Missile_time > 600)
		{
			entity->y--;
		
			Missile_time = 0;
		}

		Missile_time++;
	}
}

void Missile_draw(Entity *entity)
{
	DotMatrix_drawPixel(entity->x, entity->y);
}

Entity* Missile_create()
{
	Entity *entity = Entity_create();

	entity->type = ENTITY_MISSILE;
	entity->width = 1;
	entity->height = 1;

	entity->x = -1;
	entity->y = -1;

	entity->think = Missile_think;
	entity->draw = Missile_draw;

	return entity;
}
