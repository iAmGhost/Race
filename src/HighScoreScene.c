#include "HighScoreScene.h"
#include "Button.h"
#include "Settings.h"
#include "LCD.h"
#include <avr/io.h>


void HighScoreScene_init()
{

	lcdClear();

	lcd_puts(1, "  <High Score>");
	lcd_puts(2, "Score: ");
	lcd_putn6(Settings_getHighScore());

	while (PINB);
}
void HighScoreScene_draw()
{

}

void HighScoreScene_think()
{
	if (PINB && !(PINB & BUTTON_OK))
	{
		Scene_change(SCENE_MENU);
	}
}
