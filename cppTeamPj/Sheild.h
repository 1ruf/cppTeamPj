#pragma once
#include "Console.h"
#include <io.h>
#include <iostream>
#include "IHitable.h"

class Shield : public IHitable
{
private:
	COLOR shieldColor = COLOR::RED;
    string shieldSymbol = "▩";
    COORD position;
    COORD GetPosition() const;
    void SetPosition(COORD pos) { position = pos; }
	void SetShieldColor(COLOR color) { shieldColor = color; }
public:
    bool DetectEnemy(COORD enemyPos);
    Shield(COORD pos);

    // IHitable을(를) 통해 상속됨
    void Hit() override;
};