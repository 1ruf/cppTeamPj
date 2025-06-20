#include "Enemy.h"
#include "Console.h"
#include "Sheild.h"

void Enemy::SetEnemy()
{
	currentPos = GetConsoleResolution();
	shieldPos.X = currentPos.X / 2;
	shieldPos.Y = currentPos.Y / 2;

	int randDir = rand() % 4;
	switch (randDir)
	{
	case 0:
		objectVisual = visual.rightVisual;
		direction = Direction::RIGHT;
		currentPos.Y /= 2;
		break;
	case 1:
		objectVisual = visual.leftVisual;
		direction = Direction::LEFT;
		currentPos.Y /= 2;
		currentPos.X = 0;
		break;
	case 2:
		objectVisual = visual.upVisual;
		direction = Direction::UP;
		currentPos.X /= 2;
		currentPos.Y = 0;
		break;
	case 3:
		objectVisual = visual.downVisual;
		direction = Direction::DOWN;
		currentPos.X /= 2;
		break;
	}
	Spawn();
}

void Enemy::Spawn()
{
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << objectVisual;
}

void Enemy::Move()
{
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << "  ";

	currentPos.X += directionVectors[static_cast<int>(direction)].X;
	currentPos.Y += directionVectors[static_cast<int>(direction)].Y;

	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << objectVisual;
}

bool operator==(const COORD& FistCoord, const COORD& SecondCoord)
{
	return FistCoord.X == SecondCoord.X && FistCoord.Y == SecondCoord.Y;
}

bool Enemy::CheckShield()
{
	return currentPos == shieldPos;
}
