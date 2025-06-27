#pragma once
#include "Enums.h"
#include "Player.h"
#include "ScoreManager.h"

void OpenGameScene(Scene& _eCurScene,Player& player, ScoreManager& scoreManager);
void InitGame();
void OpenGameOverScene(Scene& _eCurScene, ScoreManager scoreManager);
void InitGameOver();
void OpenTitleScene(Scene& _eCurScene);
void InitTitle();
void OpenInfoScene(Scene& _eCurScene);
void InitInfo();
void OpenCreditScene(Scene& _eCurScene);
void InitCredit();