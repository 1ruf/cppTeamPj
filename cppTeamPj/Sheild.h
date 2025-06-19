#pragma once
#include "Console.h"
#include <io.h>
#include <iostream>

class Sheild
{
private:
	COLOR shieldColor = COLOR::RED;
    string shieldSymbol = "¢É";
    COORD position;
    COORD GetPosition() const;
    bool DetectEnemy(COORD enemyPos);
    void SetPosition(COORD pos) { position = pos; }
	void SetShieldColor(COLOR color) { shieldColor = color; }
public:
    Sheild(COORD pos);
};