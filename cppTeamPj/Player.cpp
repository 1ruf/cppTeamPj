#include "Player.h"
#include "PlayerContoller.h"

Player::Player(const string& visual,Scene* scene)
{
	visualScene = scene;
	objectVisual = visual;
	life = 3;
}
void Player::ResetPlayer()
{
	life = 3;
	playerColor = COLOR::WHITE;
	currentPos = { 0,0 };
	curMove = CUR_MOVE::UP;
}
void Player::SetPlayerColor(COLOR color, float duration)
{
	SetPlayerColor(color);
	Sleep(duration);//���� �̰� �ٲ�� �ɼ���?
	SetPlayerColor(COLOR::WHITE);
}

void Player::SetPlayerColor(COLOR color)
{
	Gotoxy(currentPos.X,currentPos.Y);
	cout << " ";
	SetColor(color);
	Gotoxy(currentPos.X,currentPos.Y);
	cout << objectVisual;
	SetColor();
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
	Gotoxy(renderPos.X, renderPos.Y);//�׸��°� ���⼭ �ϴ°� �³�?
	std::cout << plr.objectVisual;
}

void Player::RenderHpInit(COORD pos)
{
	Gotoxy(pos.X, pos.Y);
	cout << " __ __ _____                   " << endl;
	cout << "|  |  |  -  |                  " << endl;
	cout << "|     |   __|                  " << endl;
	cout << "|__|__|__|                     " << endl;
	cout << " _____________________________ " << endl;
	cout << "|                             |" << endl;
	cout << "|                             |" << endl;
	cout << "|                             |" << endl;
	cout << "|_____________________________|" << endl;

}

void Player::RenderHp(COORD pos)
{
	COORD curHpRender = pos;
	for (int i = 0; i < 3; ++i)
	{
		curHpRender.X = pos.X + 4 + (10 * i);
		curHpRender.Y = pos.Y + 6;

		Gotoxy(curHpRender.X, curHpRender.Y);
		if (i < life)
		{
			SetColor(COLOR::WHITE, COLOR::WHITE);
			cout << "    ";
			Gotoxy(curHpRender.X, curHpRender.Y + 1);
			cout << "    ";
		}
		else
		{
			SetColor(COLOR::BLACK, COLOR::BLACK);
			cout << "    ";
			Gotoxy(curHpRender.X, curHpRender.Y + 1);
			cout << "    ";
		}
		SetColor();
	}
}

void Player::Hit()
{
	SetPlayerColor(COLOR::RED, 100);
	life = life - 1;
	if (life <= 0)
	{
		GameOverAnimation(.8f,visualScene);
	}
}

void GameOverAnimation(float delayTime,Scene* visualScene)
{
	COORD resolution = GetConsoleResolution();
	SetColor(COLOR::WHITE, COLOR::WHITE);
	for (int i = 0; i <= resolution.X / 2; ++i)
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
	for (int i = 0; i <= resolution.X / 2; ++i)
	{
		for (int j = 0; j <= resolution.Y; ++j)
		{
			Gotoxy(i, j);
			cout << " ";
		}
		for (int j = 0; j <= resolution.Y; ++j)
		{
			Gotoxy(resolution.X - i, j);
			cout << " ";
		}
		Sleep(delayTime);
	}

	*visualScene = Scene::GAMEOVER;
}