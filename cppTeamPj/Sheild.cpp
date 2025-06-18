#include "Sheild.h"

Sheild::Sheild(COORD pos) : position(pos)
{
}

void Sheild::SetPosition(COORD pos)
{
    position = pos;
}

COORD Sheild::GetPosition() const
{
    return position;
}

bool Sheild::DetectEnemy(COORD enemyPos)
{
    return (enemyPos.X == position.X && enemyPos.Y == position.Y);
}