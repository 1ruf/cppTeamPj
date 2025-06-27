#pragma once
#include "PlayerContoller.h"
#include "Enums.h"
#include "Scenes.h"
#include "Console.h"
#include "Player.h"
#include "ScoreManager.h"
#include "GameOverManager.h"


class Core
{
public:
	void Run();
private:
	void Init();
	void Update(Scene& curScene, Scene& befScene, Player& player, ScoreManager& scoreManager, GameOverManager& gameoverManager);
	void Render(Scene &curScene);
};

bool CheckSceneInit(Scene& befScene, Scene& curScene);

