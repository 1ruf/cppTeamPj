#pragma once
#include<iostream>
#include"Entity.h"
#include "Enums.h"
#include "Console.h"
#include <wincontypes.h>

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
	COORD currentPos;
    int life { 0 };
	CUR_MOVE curMove{ CUR_MOVE::UP };
public:
	Player(const string& visual);
	CUR_MOVE GetDirection() { return curMove; }
	COORD GetPosition() { return currentPos; }
	void SetDirection(CUR_MOVE direction) { curMove = direction; }

	void PlayerControl(Player& player, Scene& _curScene);
	void PlayerRender(Player plr);
	void Move() override {
		Gotoxy(currentPos.X, currentPos.Y);
		cout << " ";
	};
};




