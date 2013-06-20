#include "Obstacle.h"
#include "DotMatrix.h"
#include "Settings.h"

int Obstacle_time = 0;

void Obstacle_draw(Entity *entity)
{
	DotMatrix_drawPixel(entity->x, entity->y);
	DotMatrix_drawPixel(entity->x + 1, entity->y);
	DotMatrix_drawPixel(entity->x, entity->y + 1);
	DotMatrix_drawPixel(entity->x + 1, entity->y + 1);
}

void Obstacle_think(Entity *entity)
{
	if (entity->y > 10)
	{
		entity->remove = TRUE;
	}

	if (Obstacle_time > Settings_getGameSpeed())
	{
		entity->y += 1;

		Obstacle_time = 0;
	}

	Obstacle_time++;
}

Entity* Obstacle_create()
{
	Entity *entity = Entity_create();

	entity->width = 2;
	entity->height = 2;
	entity->type = ENTITY_OBSTACLE;
	entity->draw = Obstacle_draw;
	entity->think = Obstacle_think;

	return entity;
}
