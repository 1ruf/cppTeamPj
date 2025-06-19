#include "Enemy.h"
#include "Console.h"

void Enemy::SetEnemy()
{
	// �ϴ� �ܼ�â ũ�� coord�� ���
	COORD coord = GetConsoleResolution();

	// 0 1 2 3�� ������ �ϳ� �̱�
	int randDir = rand() % 4;
	// ���� ���� switch�� ������
	// ���⼭�� ������ġ ���� �� direction���� �� ���־� �����ϱ�
	switch (randDir)
	{
	case 0:
		// ����� right
		objectVisual = visual.rightVisual;
		direction = Direction::RIGHT;
		coord.Y /= 2;
		break;
	case 1:
		// ����� left
		objectVisual = visual.leftVisual;
		direction = Direction::LEFT;
		coord.Y /= 2;
		coord.X = 0;
		break;
	case 2:
		// ����� up
		objectVisual = visual.upVisual;
		direction = Direction::UP;
		coord.X /= 2;
		coord.Y = 0;
		break;
	case 3:
		// ����� down
		objectVisual = visual.downVisual;
		direction = Direction::DOWN;
		coord.X /= 2;
		break;
	}
	Spawn(coord);
}

void Enemy::Spawn(COORD coord)
{
	// ���� ��ġ���� �Ű����� coord �ֱ�
	currentPos = coord;
	// �Ű������� ���� coord�� ��ġ�� Ŀ�� �ű��
	Gotoxy(coord.X, coord.Y);
	// ������ objectVisual �׷��ֱ�
	std::cout << objectVisual;
}

void Enemy::Move()
{
	// ���� ��ġ�� �ִ� �� ����������
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << "  ";

	// ���ο� ��ġ�� �̵���Ű��
	// C ��Ÿ�� ĳ����
	//currentPos.X += directionVectors[(int)direction].X;

	// C++ ����ȯ ������. static_cast<Ÿ��>(���)
	// C++ ����ȯ �����ڸ� ���� �����϶� �̸� ������ ����ش�.
	currentPos.X += directionVectors[static_cast<int>(direction)].X;
	currentPos.Y += directionVectors[static_cast<int>(direction)].Y;

	// ���� �̵��� ��ġ�� Ŀ�� �ű�� �׷��ֱ�
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << objectVisual;
}
