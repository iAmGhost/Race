#pragma once
#include "Macro.h"
#include "DotMatrix.h"
#include "list.h"
#define ENTITY_NONE 0
#define ENTITY_PLAYER 1
#define ENTITY_ROAD 2
#define ENTITY_OBSTACLE 3
#define ENTITY_MISSILE 4
#define Entity_isCollide(A, B) !((A->y + A->height-1) < B->y || A->y > (B->y + B->height-1) || (A->x > (B->x + B->width-1) || (A->x + A->width-1) < B->x))

typedef struct Entity {
	struct list_elem elem;
	int type;
	int x;
	int y;
	int width;
	int height;
	int enabled;
	int remove;
	void (*draw)(struct Entity*);
	void (*think)(struct Entity*);
} Entity;

Entity* Entity_create();
void Entity_remove();
