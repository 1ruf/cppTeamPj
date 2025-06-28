#include "InfoScene.h"

void InfoScene(Scene& _eCurScene)
{
	InfoSceneRender();
	InfoSceneUpdate(_eCurScene);
}

void InfoSceneInit()
{
	system("cls");
}

void InfoSceneUpdate(Scene& _eCurScene)
{
	InfoSceneExit(_eCurScene);
}

void InfoSceneRender()
{
	COORD consoleSize = GetConsoleResolution();

	Gotoxy(3, 1);
	cout << "< 종료:ESC >\n\n";
	cout << "HIDER 게임 정보 페이지입니다." << endl;
	Gotoxy(0, consoleSize.Y / 2 - 20);
	cout << "이 게임은 적을 피해 방패 뒤로 숨는 게임입니다.\n";
	cout << "-조작키-\n[\n- 상호작용 : SPACE\n- 나가기 : ESC\n- 이동(상,하,좌,우) : W,S,A,D\n]\n\n";
	cout << "하얀화살표(적) : 하얀색 적은 플레이어가 피해야 합니다.\n\t이 적은 플레이어가 맞으면 안됩니다.\n";
	cout << "빨간화살표(적) : ";
	SetColor(COLOR::RED);
	cout << "빨간색"; 
	SetColor();
	cout << " 적은 플레이어가 맞아야 합니다.\n\t이 적은 방패가 맞으면 안됩니다.\n\n";
	cout << "게임의 난이도는 점수에 비례에서 증가합니다!";


	SetColor();
}

void InfoSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
