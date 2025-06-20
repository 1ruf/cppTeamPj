#pragma once
#include<iostream>
#include"Entity.h"
#include "Enums.h"

enum class CUR_MOVE
{
    UP,
	DOWN,
	LEFT,
	RIGHT
};

class Player : public Entity
{
private:
    int life { 0 };
	CUR_MOVE curMove{ CUR_MOVE::UP };
public:
	void SetDirection(CUR_MOVE direction) { curMove = direction; }
	CUR_MOVE GetDirection() { return curMove; }
	Player(const string& visual)
	{
		objectVisual = visual;
	}

    void Move() override { }
};

void PlayerControl(Player& player,Scene& _curScene);
void PlayerRender(Player plr);


