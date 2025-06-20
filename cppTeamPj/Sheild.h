#pragma once
#include "Console.h"
#include <io.h>
#include <iostream>

class Shield
{
private:
	COLOR shieldColor = COLOR::RED;
    string shieldSymbol = "¢É";
    COORD position;
    COORD GetPosition() const;
    void SetPosition(COORD pos) { position = pos; }
	void SetShieldColor(COLOR color) { shieldColor = color; }
public:
    bool DetectEnemy(COORD enemyPos);
    Shield(COORD pos);
};