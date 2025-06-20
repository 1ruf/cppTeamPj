#include "PlayerContoller.h"

void HandleInput(Player& player, Scene& _curScene)
{
	Key key = KeyController();
	switch (key)
	{
	case Key::W:
		player.SetDirection(CUR_MOVE::UP); 
		system("cls");
		break;
	case Key::A:
		player.SetDirection(CUR_MOVE::LEFT);
		system("cls");
		break;
	case Key::S:
		player.SetDirection(CUR_MOVE::DOWN);
		system("cls");
		break;
	case Key::D:
		player.SetDirection(CUR_MOVE::RIGHT);
		system("cls");
		break;
	case Key::SPACE:
		break;
	case Key::ESC:
		_curScene = Scene::PAUSE;
		system("cls");//clsµé Áö¿ì¼À
		break;
	default:
		break;
	}
}
