#include "TitleScene.h"
#include "Console.h"
#include <fcntl.h>
#include <io.h>

void TitleScene(Scene& _eCurScene)
{
	TitleSceneRender();
	TitleSceneUpdate();
}

void TitleSceneRender()
{
	COORD consoleSize = GetConsoleResolution();

	Gotoxy(consoleSize.X / 2 - 5, consoleSize.Y / 2 - 1);

	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"   ▄█    █▄     ▄█  ████████▄     ▄████████    ▄████████ ";
	wcout << L"  ███    ███   ███  ███   ▀███   ███    ███   ███    ███ ";
	wcout << L"  ███    ███   ███▌ ███    ███   ███    █▀    ███    ███	";
	wcout << L" ▄███▄▄▄▄███▄▄ ███▌ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀ ";
	wcout << L"▀▀███▀▀▀▀███▀  ███▌ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ";
	wcout << L"  ███    ███   ███  ███    ███   ███    █▄  ▀███████████ ";
	wcout << L"  ███    ███   ███  ███   ▄███   ███    ███   ███    ███ ";
	wcout << L"  ███    █▀    █▀   ████████▀    ██████████   ███    ███ ";
	wcout << L"                                              ███    ███ ";
}

void TitleSceneUpdate()
{

}
