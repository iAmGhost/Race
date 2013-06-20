#include "Player.h"
#include "Joystick.h"

#define PLAYERFLAG_ENABLED 0
#define PLAYERFLAG_DISABLED 1

void Player_draw(Entity *entity)
{
	DotMatrix_drawPixel(entity->x + 1, entity->y);
	DotMatrix_drawPixel(entity->x + 1, entity->y + 1);
	DotMatrix_drawPixel(entity->x, entity->y + 1);
	DotMatrix_drawPixel(entity->x + 2, entity->y + 1);
}
	
void Player_think(Entity *entity)
{
	entity->x = (Joystick_getValue() / 128);
}

Entity* Player_create()
{
	Entity *entity = Entity_create();

	entity->type = ENTITY_PLAYER;
	entity->width = 3;
	entity->height = 2;
	entity->draw = Player_draw;
	entity->think = Player_think;

	return entity;
}

