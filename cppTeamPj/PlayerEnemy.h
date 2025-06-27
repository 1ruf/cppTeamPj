#pragma once
#include "Enemy.h"

class PlayerEnemy : public Enemy
{
public:

    PlayerEnemy(int randNum) : Enemy(randNum)
    {

    }

    void Render() override;
};

