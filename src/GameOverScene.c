#include <avr/io.h>
#include "GameOverScene.h"
#include "Settings.h"
#include "LCD.h"
#include "Button.h"
#include "DotMatrix.h"

void GameOverScene_init()
{
	unsigned int score = Settings_getLastScore();
	unsigned int highScore = Settings_getHighScore();

	DotMatrix_reset();
	
	lcdClear();

	if (score > highScore)
	{
		lcd_puts(1," <High Score!>");
		Settings_setHighScore(score);
	}
	else
	{
		lcd_puts(1,"  <Game Over>");
	}

	lcd_puts(2, "Score:");
	lcd_putn6(Settings_getLastScore());

	while (PINB);

}

void GameOverScene_draw()
{
}

void GameOverScene_think()
{

	if (PINB && !(PINB & BUTTON_OK))
	{
		Scene_change(SCENE_MENU);
	}
}
