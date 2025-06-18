#pragma once
#include "Console.h"
#include <io.h>
#include <iostream>

class Sheild
{
private:
    COORD position;

public:
    Sheild(COORD pos);
    void SetPosition(COORD pos);
    COORD GetPosition() const;
    bool DetectEnemy(COORD enemyPos);
};