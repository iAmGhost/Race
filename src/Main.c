#include "MenuScene.h"
#include "Devices.h"
#include "Macro.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Proximity.h"
#include "Random.h"
#include "Settings.h"

int main()
{
	Devices_init();
	Random_randomize(Proximity_getValue());

	Scene_change(SCENE_MENU);

	while (1)
	{
		Scene_think();
		Scene_draw();
	}

	return 0;
}
