#include "Settings.h"	
#include <avr/eeprom.h>
#define HIGHSCORE_SAVED_FLAG (uint8_t *)0x0000
#define HIGHSCORE_ADDR (uint8_t *)0x0001
int Settings_gameSpeed = 1500;
unsigned int Settings_lastScore = 0;
int Settings_buttonLock = 0;


void Settings_setGameSpeed(int speed)
{
	Settings_gameSpeed = speed;

	if (Settings_gameSpeed < 0)
	{
		Settings_gameSpeed = 0;
	}
}

int Settings_getGameSpeed()
{
	return Settings_gameSpeed;
}

void Settings_setLastScore(unsigned int score)
{
	Settings_lastScore = score;
}

unsigned int Settings_getLastScore()
{
	return Settings_lastScore;
}

void Settings_setHighScore(unsigned int score)
{
	eeprom_write_word(HIGHSCORE_ADDR, score);
	eeprom_write_byte(HIGHSCORE_SAVED_FLAG, 1);
}

unsigned int Settings_getHighScore()
{
	int highscore_flag = eeprom_read_byte(HIGHSCORE_SAVED_FLAG);

	if (highscore_flag == 1)
	{
		return eeprom_read_word(HIGHSCORE_ADDR);
	}

	return 0;
}
