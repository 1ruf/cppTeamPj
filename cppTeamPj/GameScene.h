#pragma once
#include "Sheild.h"
#include "Enums.h"
#include "Player.h"
#include "PlayerContoller.h"
#include <Windows.h>
#include <iostream>
#include "EnemyManager.h"

void GameScene(Scene& _eCurScene, Player& player);

void GameSceneUpdate(Scene& _eCurScene, Player& player);
void GameSceneRender();

void PlayerControl(Player& player,Scene& _curScene);
