#include "Scene.h"
#include "Macro.h"
#include "Settings.h"
//Scenes Start
#include "MenuScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "HighScoreScene.h"
//Scens End

static int scene;

void Scene_init()
{
	switch (scene)
	{
	case SCENE_MENU:
		MenuScene_init();
		break;

	case SCENE_GAME:
		GameScene_init();
		break;

	case SCENE_GAMEOVER:
		GameOverScene_init();
		break;

	case SCENE_HIGHSCORE:
		HighScoreScene_init();
		break;
	}
}

void Scene_draw()
{
	switch (scene)
	{
	case SCENE_MENU:
		MenuScene_draw();
		break;

	case SCENE_GAME:
		GameScene_draw();
		break;

	case SCENE_GAMEOVER:
		GameOverScene_draw();
		break;

	case SCENE_HIGHSCORE:
		HighScoreScene_draw();
		break;
	}
}

void Scene_think()
{
	switch (scene)
	{
	case SCENE_MENU:
		MenuScene_think();
		break;

	case SCENE_GAME:
		GameScene_think();
		break;

	case SCENE_GAMEOVER:
		GameOverScene_think();
		break;

	case SCENE_HIGHSCORE:
		HighScoreScene_think();
		break;
	}
}

void Scene_change(int scene_type)
{
	scene = scene_type;
	Scene_init();
}
