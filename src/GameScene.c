#include "GameScene.h"
#include "Button.h"
#include "Player.h"
#include "Road.h"
#include "LCD.h"
#include "list.h"
#include "Joystick.h"
#include "Obstacle.h"
#include "Missile.h"
#include "Random.h"
#include "Settings.h"

int GameScene_time = 0;

unsigned int score = 0;
int life = 3;

int levelingScore = 0;

struct list entities;

Entity *player;
Entity *missile;

int button_lock = FALSE;

void GameScene_redrawScore();
void GameScene_redrawLife();

void GameScene_init()
{
	Settings_setGameSpeed(2000);

	GameScene_time = 0;
	score = 0;
	life = 3;
	button_lock = FALSE;

	list_init(&entities);

	lcdClear();
	lcd_puts(1, "Score:");
	lcd_puts(2, "Life :");

	GameScene_redrawScore();
	GameScene_redrawLife();

	player = Player_create();
	player->x = 0;
	player->y = 8;

	list_push_back(&entities, &player->elem);

	missile = Missile_create();
	missile->y = 10;

	list_push_back(&entities, &missile->elem);
}

void GameScene_redrawScore()
{
	lcd_gotoxy(8, 1);
	lcd_putn6(score);
}

void GameScene_redrawLife()
{
	int i;

	for (i = 0; i < 5; i++)
	{
		lcd_gotoxy(8, 2 + i);

		if (i < life)
		{
			putString("@");
		}
		else
		{
			putString(" ");
		}
	}
}

void GameScene_drawEntities()
{
	struct list_elem *e;
	Entity *entity;

	if (list_empty(&entities))
	{
		return ;
	}

	for (e = list_begin(&entities); e != list_end(&entities); e = list_next(e))
    {
		entity = list_entry(e, Entity, elem);
		entity->draw(entity);
	}
}

void GameScene_free()
{
	struct list_elem *e;
	Entity *entity;

	for (e = list_begin(&entities); e != list_end(&entities); e = list_next(e))
    {
		entity = list_entry(e, Entity, elem);

		Entity_remove(entity);
	}
}

void GameScene_draw() 
{
	GameScene_drawEntities();

	DotMatrix_draw();
	DotMatrix_clear();
}

void GameScene_innerThink()
{
	Entity *entity;

	if (GameScene_time > 5000 + (Settings_getGameSpeed() * 2))
	{
		entity = Obstacle_create();

		entity->x = Random_nextInt() % 8;
		entity->y = 0;

		list_push_back(&entities, &entity->elem);

		GameScene_time = 0;
	}

	if (!missile->enabled && PINB == BUTTON_1 && !button_lock)
	{
		missile->x = player->x + 1;
		missile->y = player->y;

		button_lock = TRUE;
	}

	if (!(PINB & BUTTON_1))
	{
		button_lock = FALSE;
	}

	if (life == 0)
	{
		Settings_setLastScore(score);
		GameScene_free();
		Scene_change(SCENE_GAMEOVER);
	}

	if (levelingScore >= 1000)
	{
		Settings_setGameSpeed(Settings_getGameSpeed() - 300);
		levelingScore = 0;
	}
	GameScene_time++;
}

void GameScene_thinkEntities()
{
	struct list_elem *e;
	Entity *entity;

	if (list_empty(&entities))
	{
		return ;
	}

	for (e = list_begin(&entities); e != list_end(&entities); e = list_next(e))
    {
		entity = list_entry(e, Entity, elem);
		entity->think(entity);

		if (entity->type == ENTITY_OBSTACLE)
		{
			if (Entity_isCollide(missile, entity))
			{
				entity->remove = TRUE;
				missile->y = -1;

				score += 100;
				levelingScore += 100;

				GameScene_redrawScore();
			}
			
			if (Entity_isCollide(player, entity))
			{
				entity->remove = TRUE;

				life--;
				
				GameScene_redrawLife();
			}
		}


		if (entity->remove)
		{
			Entity_remove(entity);
		}
	}
}

void GameScene_think()
{
	GameScene_thinkEntities();
	GameScene_innerThink();
}
