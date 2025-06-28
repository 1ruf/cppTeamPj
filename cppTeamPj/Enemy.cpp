#include "Enemy.h"
#include "Console.h"
#include <iostream>


void Enemy::SetEnemy(int randNum)
{
	currentPos = GetConsoleResolution();
	shieldPos.X = currentPos.X / 2;
	shieldPos.Y = currentPos.Y / 2;

	switch (randNum)
	{
	case 0:
		objectVisual = visual.rightMoveVisual;
		direction = Direction::RIGHT;
		currentPos.Y /= 2;
		break;
	case 1:
		objectVisual = visual.leftMoveVisual;
		direction = Direction::LEFT;
		currentPos.Y /= 2;
		currentPos.X = 0;
		break;
	case 2:
		objectVisual = visual.upMoveVisual;
		direction = Direction::UP;
		currentPos.X /= 2;
		currentPos.Y = 0;
		break;
	case 3:
		objectVisual = visual.downMoveVisual;
		direction = Direction::DOWN;
		currentPos.X /= 2;
		currentPos.Y -= 1;
		break;
	}
}

void Enemy::Move()
{
	Erase();
	currentPos.X += directionVectors[static_cast<int>(direction)].X;
	currentPos.Y += directionVectors[static_cast<int>(direction)].Y;
	Render();
}


void Enemy::Render()
{
}

void Enemy::Erase()
{
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << "  ";
}

inline bool operator==(const COORD& FistCoord, const COORD& SecondCoord)
{
	return FistCoord.X == SecondCoord.X && FistCoord.Y == SecondCoord.Y;
}

bool Enemy::CheckShield()
{
	return currentPos == shieldPos;
}

bool Enemy::CheckPlayer(COORD playerPos)
{
	return currentPos == playerPos;
}
