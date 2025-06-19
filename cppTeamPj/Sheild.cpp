#include "Sheild.h"
#include <fcntl.h>

Sheild::Sheild(COORD pos) : position(pos)
{
 	Gotoxy(position.X, position.Y);
    SetColor(shieldColor);
    std::cout << shieldSymbol; //�ű��ϰԵ� �����ڵ� ��ȯ�ϴ°� ���� �ȵ�
    SetColor(COLOR::WHITE);
}

COORD Sheild::GetPosition() const
{
    return position;
}

bool Sheild::DetectEnemy(COORD enemyPos)
{
    return (enemyPos.X == position.X && enemyPos.Y == position.Y);
}