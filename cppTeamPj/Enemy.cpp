#include "Enemy.h"
#include "Console.h"

void Enemy::SetEnemy()
{
	// 일단 콘솔창 크기 coord에 담기
	COORD coord = GetConsoleResolution();

	// 0 1 2 3중 랜덤값 하나 뽑기
	int randDir = rand() % 4;
	// 값에 따라 switch문 돌리기
	// 여기서는 스폰위치 설정 및 direction설정 및 비주얼 설정하기
	switch (randDir)
	{
	case 0:
		// 여기는 right
		objectVisual = visual.rightVisual;
		direction = Direction::RIGHT;
		coord.Y /= 2;
		break;
	case 1:
		// 여기는 left
		objectVisual = visual.leftVisual;
		direction = Direction::LEFT;
		coord.Y /= 2;
		coord.X = 0;
		break;
	case 2:
		// 여기는 up
		objectVisual = visual.upVisual;
		direction = Direction::UP;
		coord.X /= 2;
		coord.Y = 0;
		break;
	case 3:
		// 여기는 down
		objectVisual = visual.downVisual;
		direction = Direction::DOWN;
		coord.X /= 2;
		break;
	}
	Spawn(coord);
}

void Enemy::Spawn(COORD coord)
{
	// 현재 위치에서 매개변수 coord 넣기
	currentPos = coord;
	// 매개변수로 받은 coord로 위치로 커서 옮기기
	Gotoxy(coord.X, coord.Y);
	// 설정된 objectVisual 그려주기
	std::cout << objectVisual;
}

void Enemy::Move()
{
	// 이전 위치에 있던 적 지워버리기
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << "  ";

	// 새로운 위치로 이동시키기
	// C 스타일 캐스팅
	//currentPos.X += directionVectors[(int)direction].X;

	// C++ 형변환 연산자. static_cast<타입>(대상)
	// C++ 형변환 연산자를 쓰면 컴파일때 미리 에러를 잡아준다.
	currentPos.X += directionVectors[static_cast<int>(direction)].X;
	currentPos.Y += directionVectors[static_cast<int>(direction)].Y;

	// 새로 이동된 위치로 커서 옮기고 그려주기
	Gotoxy(currentPos.X, currentPos.Y);
	std::cout << objectVisual;
}
