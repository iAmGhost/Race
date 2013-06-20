#pragma once
#define SCENE_NONE 0
#define SCENE_MENU 1
#define SCENE_GAME 2
#define SCENE_GAMEOVER 3
#define SCENE_HIGHSCORE 4

void Scene_init();
void Scene_draw();
void Scene_think();
void Scene_change(int scene_type);
