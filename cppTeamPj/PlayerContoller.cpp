#include "PlayerContoller.h"

void HandleInput(POS& _pos, Menu& _menu)
{
	Key key = KeyController();
	switch (key)
	{
	case Key::W:
		_pos.y--;
		break;
	case Key::A:
		_pos.x--;
		break;
	case Key::S:
		_pos.y++;
		break;
	case Key::D:
		_pos.x++;
		break;
	case Key::SPACE:
		// Handle space key action
		break;
	case Key::ESC:
		// Handle escape key action
		break;
	default:
		break;
}
