#include "Enums.h"
#include "ScoreManager.h"
#include<Windows.h>
#include "GameOverManager.h"
#pragma once
void GameOverScene(Scene& curScene, ScoreManager scoreManager, GameOverManager& gameoverManager);

void GameOverInit();
void GameOverUpdate(Scene& curScene, ScoreManager scoreManager,GameOverManager& gameoverManager);
void GameOverRender(Scene curScene,GameOverManager& gameoverManager);

void SelectRender(int index,COORD pos);

void RenderLogo(Scene curScene,GameOverManager& manager);
Scene GameSceneInput();