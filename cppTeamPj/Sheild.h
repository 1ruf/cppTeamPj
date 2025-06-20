#pragma once
#include "Console.h"
#include <io.h>
#include <iostream>

class Sheild
{
private:
	COLOR shieldColor = COLOR::RED;
    string shieldSymbol = "��";
    COORD position;
    COORD GetPosition() const;
    void SetPosition(COORD pos) { position = pos; }
	void SetShieldColor(COLOR color) { shieldColor = color; }
public:
    bool DetectEnemy(COORD enemyPos);
    Sheild(COORD pos);
};