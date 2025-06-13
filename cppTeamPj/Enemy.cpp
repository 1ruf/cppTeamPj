#include "Enemy.h"


void Enemy::SetEnemy()
{
	int randDir = rand() % 4;
	switch (randDir)
	{
	case 0:
		// 여기는 right
		objectVisual = visual.rightVisual;
		direction = Direction::RIGHT;
		break;
	case 1:
		// 여기는 left
		objectVisual = visual.leftVisual;
		direction = Direction::LEFT;
		break;
	case 2:
		// 여기는 up
		objectVisual = visual.upVisual;
		direction = Direction::UP;
		break;
	case 3:
		// 여기는 down
		objectVisual = visual.downVisual;
		direction = Direction::DOWN;
		break;
	}
}

void Enemy::Spawn()
{

}

void Enemy::Move()
{
	
}
