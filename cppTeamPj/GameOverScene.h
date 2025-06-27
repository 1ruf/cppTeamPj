#include "Enums.h"
#include "ScoreManager.h"
#include "GameOverManager.h"
#include<Windows.h>
#pragma once
void GameOverScene(Scene& curScene, ScoreManager scoreManager, GameOverManager& gameoverManager);

void GameOverInit();
void GameOverUpdate(Scene& curScene, ScoreManager scoreManager,GameOverManager& gameoverManager);
void GameOverRender(Scene curScene, ScoreManager scoreManager,GameOverManager& gameoverManager);

void SelectRender(int index,COORD pos);
void SidelineRender(int index);

void RenderLogo(Scene curScene,GameOverManager& manager);
Scene GameSceneInput(int& index);