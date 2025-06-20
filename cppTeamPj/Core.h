#pragma once
#include "PlayerContoller.h"
#include "Enums.h"
#include "Scenes.h"
#include "Console.h"
#include "Player.h"

class Core
{
public:
	void Run();
private:
	void Init();
	void Update(Scene& curScene, Player& player);
	void Render(Scene &curScene);
};

