#pragma once
#include "Enums.h"
#include "Player.h"

void OpenGameScene(Scene& _eCurScene,Player& player);
void InitGame();
void OpenTitleScene(Scene& _eCurScene);
void InitTitle();
void OpenInfoScene(Scene& _eCurScene);
void InitInfo();
void OpenCreditScene(Scene& _eCurScene);
void InitCredit();