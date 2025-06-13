#pragma once
#include"Enums.h"
class Core
{
public:
	void Run();
private:
	void Init();
	void Update(Scene& curScene);
	void Render(Scene &curScene);
};

