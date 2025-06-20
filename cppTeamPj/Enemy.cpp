#include "Enemy.h"
#include "Console.h"

void Enemy::SetEnemy()
{
	COORD coord = GetConsoleResolution();

	int randDir = rand() % 4;
	switch (randDir)
	{
	case 0:
		objectVisual = visual.rightVisual;
		direction = Direction::RIGHT;
		coord.Y /= 2;
		break;
	case 1:
		objectVisual = visual.leftVisual;
		direction = Direction::LEFT;
		coord.Y /= 2;
		coord.X = 0;
		break;
	case 2:
		objectVisual = visual.upVisual;
		direction = Direction::UP;
		coord.X /= 2;
		coord.Y = 0;
		break;
	case 3:
		objectVisual = visual.downVisual;
		direction = Direction::DOWN;
		coord.X /= 2;
		break;
	}
	Spawn(coord);
}

void Enemy::Spawn(COORD coord)
{
	currentPos = coord;
	Gotoxy(coord.X, coord.Y);
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
