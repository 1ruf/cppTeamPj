#include "Player.h"
#include "PlayerContoller.h"

Player::Player(const string& visual)
{
	objectVisual = visual;
}

void Player::PlayerControl(Player & player, Scene & _curScene)
{
	HandleInput(player, _curScene);
	player.PlayerRender(player);
}

void Player::PlayerRender(Player plr)
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	CUR_MOVE curMove = plr.GetDirection();
	COORD renderPos = { centerPos.X, centerPos.Y };

	switch (curMove)
	{
	case CUR_MOVE::UP:
		renderPos.Y -= 2;
		break;
	case CUR_MOVE::DOWN:
		renderPos.Y += 2;
		break;
	case CUR_MOVE::LEFT:
		renderPos.X -= 4;
		break;
	case CUR_MOVE::RIGHT:
		renderPos.X += 4;
		break;
	default:
		break;
	}
	currentPos = renderPos;
	Gotoxy(renderPos.X, renderPos.Y);//그리는걸 여기서 하는게 맞나?
	std::cout << plr.objectVisual;
}

void Player::Hit()
{
	life--;
	if (life <= 0)
	{
		GameOverAnimation(50.0f);
		cout << "GAME OVER";
	}
}

void GameOverAnimation(float delayTime)
{
	COORD resolution = GetConsoleResolution();
	SetColor(COLOR::WHITE, COLOR::WHITE);
	for (int i = 0; i < resolution.X / 2; ++i)
	{
		for (int j = 0; j < resolution.Y; ++j)
		{
			Gotoxy(i, j);
			cout << " ";
		}
		for (int j = 0; j < resolution.Y; ++j)
		{
			Gotoxy(resolution.X - i, j);
			cout << " ";
		}
		Sleep(delayTime);
	}

	SetColor();
}