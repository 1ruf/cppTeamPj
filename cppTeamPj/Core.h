#pragma once
#include"Enums.h"
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

