#include "shieldEnemy.h"
#include "Console.h"

void ShieldEnemy::Render()
{
	SetColor(COLOR::LIGHT_RED, COLOR::BLACK);
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << objectVisual;
	SetColor(COLOR::WHITE, COLOR::BLACK);
}
