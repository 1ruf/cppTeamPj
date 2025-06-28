#include "PlayerContoller.h"

void HandleInput(Player& player, Scene& _curScene)
{
	Key key = KeyController();
	switch (key)
	{
	case Key::W:
		player.SetDirection(CUR_MOVE::UP); 
		player.Move();
		break;
	case Key::A:
		player.SetDirection(CUR_MOVE::LEFT);
		player.Move();
		break;
	case Key::S:
		player.SetDirection(CUR_MOVE::DOWN);
		player.Move();
		break;
	case Key::D:
		player.SetDirection(CUR_MOVE::RIGHT);
		player.Move();
		break;
	case Key::SPACE:
		break;
	case Key::ESC:
		_curScene = Scene::MENU;
		system("cls");
		break;
	default:
		break;
	}
}
