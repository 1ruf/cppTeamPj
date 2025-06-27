#pragma once
#include <iostream>
#include "IHitable.h"
#include "Entity.h"
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

class Player : public Entity,public IHitable
{
private:
    int life { 3 };
	COLOR playerColor = COLOR::WHITE;
	COORD currentPos;
	CUR_MOVE curMove{ CUR_MOVE::UP };
public:
	Scene* visualScene;

	Player(const string& visual,Scene* visualScene);

	CUR_MOVE GetDirection() { return curMove; }
	COORD GetPosition() { return currentPos; }

	void ResetPlayer();
	void SetPlayerColor(COLOR color,float duration);
	void SetPlayerColor(COLOR color);
	void SetDirection(CUR_MOVE direction) { curMove = direction; }
	void PlayerControl(Player& player, Scene& _curScene);
	void PlayerRender(Player plr);
	void Move() override {
		Gotoxy(currentPos.X, currentPos.Y);
		cout << " ";
	};

	// IHitable상속 (저거 순수가상함수라 무조건 구현&상속으로만 구현ㄱㄴ)
	void Hit() override;
};
void GameOverAnimation(float delayTime,Scene* visualScene);



