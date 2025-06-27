#pragma once
#include "Enemy.h"

class ShieldEnemy : public Enemy
{
public:
    ShieldEnemy(int randNum) : Enemy(randNum)
    {

    }

    void Render() override;
};

