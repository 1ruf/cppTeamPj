#pragma once
#include "Enums.h"
#include "Player.h"
#include "ScoreManager.h"
#include "GameOverManager.h"

void OpenGameScene(Scene& _eCurScene,Player& player, ScoreManager& scoreManager);
void InitGame(ScoreManager& scoreManager, Player& player);
void OpenGameOverScene(Scene& _eCurScene, ScoreManager scoreManager,GameOverManager& gameoverManager);
void InitGameOver();
void OpenTitleScene(Scene& _eCurScene);
void InitTitle();
void OpenInfoScene(Scene& _eCurScene);
void InitInfo();
void OpenCreditScene(Scene& _eCurScene);
void InitCredit();