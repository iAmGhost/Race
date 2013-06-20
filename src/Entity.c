#include "Entity.h"
#include "list.h"

Entity* Entity_create()
{
	Entity *entity = NEW(Entity);

	entity->type = ENTITY_NONE;
	entity->x = 0;
	entity->y = 0;
	entity->width = 0;
	entity->height = 0;
	entity->enabled = 1;
	entity->remove = 0;

	return entity;
}

void Entity_remove(Entity *entity)
{
	list_remove(&entity->elem);

	free(entity);
}
