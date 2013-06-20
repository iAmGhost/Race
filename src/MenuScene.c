#include <avr/io.h>
#include <util/delay.h>
#include "Macro.h"
#include "UART.h"
#include "Button.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "Settings.h"
#include "LCD.h"
#define MENU_START 1
#define MENU_SCORE 2
#define MENU_FIRST MENU_START
#define MENU_END MENU_SCORE

int cursor = MENU_START;

void MenuScene_redrawMenu()
{
	int i;

	for (i = MENU_FIRST; i <= MENU_END; i++)
	{
		lcd_gotoxy(1, i);

		if (cursor == i)
		{
			putString("->");
		}
		else
		{
			putString("  ");
		}
	}
}

void MenuScene_init()
{
	lcdClear();

	lcd_puts(MENU_START, "   Game Start");
	lcd_puts(MENU_SCORE, "   High Score");

	MenuScene_redrawMenu();

	while (PINB);
}

void MenuScene_draw()
{
	
}

void MenuScene_think()
{
	switch (PINB)
	{
	case BUTTON_UP:
		if (cursor != MENU_START)
		{
			cursor -= 1;
			MenuScene_redrawMenu();
		}
		break;

	case BUTTON_DOWN:
		if (cursor != MENU_END)
		{
			cursor += 1;
			MenuScene_redrawMenu();
		}
		break;

	case BUTTON_OK:
		if (cursor == MENU_START)
		{
			Scene_change(SCENE_GAME);
		}
		else if (cursor == MENU_SCORE)
		{
			Scene_change(SCENE_HIGHSCORE);
		}
		break;
	}
}
