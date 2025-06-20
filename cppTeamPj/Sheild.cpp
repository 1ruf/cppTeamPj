#include "Sheild.h"
#include <fcntl.h>

Shield::Shield(COORD pos) : position(pos)
{
 	Gotoxy(position.X, position.Y);
    SetColor(shieldColor);
    std::cout << shieldSymbol; //�ű��ϰԵ� �����ڵ� ��ȯ�ϴ°� ���� �ȵ�
    SetColor(COLOR::WHITE);
}

COORD Shield::GetPosition() const
{
    return position;
}

bool Shield::DetectEnemy(COORD enemyPos)
{
    return (enemyPos.X == position.X && enemyPos.Y == position.Y);
}