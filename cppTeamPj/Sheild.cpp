#include "Sheild.h"
#include <fcntl.h>

Shield::Shield(COORD pos) : position(pos)
{
 	Gotoxy(position.X, position.Y);
    SetColor(shieldColor);
    std::cout << shieldSymbol; //신기하게도 유니코드 변환하는거 쓰면 안됨
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