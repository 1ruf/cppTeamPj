#include "KeyContoller.h"
#include<Windows.h>

Key KeyController()
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		return Key::W;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		return Key::A;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		return Key::S;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		return Key::D;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		return Key::SPACE;
	}
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		return Key::ESC;
	}
	return Key::FAIL;
}