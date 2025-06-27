#include "Enums.h"
#include "ScoreManager.h"
#include<Windows.h>
#pragma once
void GameOverScene(Scene& curScene, ScoreManager scoreManager);

void GameOverInit();
void GameOverUpdate(Scene& curScene, ScoreManager scoreManager);
void GameOverRender();

void SelectRender(int index,COORD pos);
Scene GameSceneInput();