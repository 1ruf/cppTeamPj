#include "PlayerEnemy.h"
#include "Console.h"

void PlayerEnemy::Render()
{
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << objectVisual;
}
