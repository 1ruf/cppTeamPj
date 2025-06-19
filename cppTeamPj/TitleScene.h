#pragma once
#include"Console.h"
#include"Enums.h"
#include <fcntl.h>
#include <io.h>
#include "KeyContoller.h"

void TitleScene(Scene& _eCurScene,Menu& _eCurMenu);

void TitleSceneRender();
void TitleSceneUpdate(Scene& _eCurScene,Menu& _eCurMenu);

void RenderCredit();
void RenderInfo();

void RenderBox();

Menu TitleSceneInput();


class SelectBar
{
private:
	int selectIndex{ 0 };

	int _width = 13;
	int _height = 3;
public:
	void SetIndex(int index);
	int GetIndex();
	SelectBar(int width = 15,int height = 5) 
	{ 
		_width = width;
		_height = height;
	}
	void Draw(COORD pos, COLOR textColor = COLOR::WHITE, COLOR bgColor = COLOR::BLACK)
	{
		int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

		int xVal = _width % 2 == 0 ? _width / 2 : _width / 2 - 1;
		int yVal = _height % 2 == 0 ? _height / 2 : _height / 2 - 1;
		SetColor(textColor,bgColor);

		Gotoxy(pos.X - xVal, pos.Y - yVal);
		wcout << L"¦®";
		Gotoxy(pos.X + xVal, pos.Y - yVal);
		wcout << L" ¦¯" << endl;
		Gotoxy(pos.X - xVal, pos.Y + yVal);
		wcout << L"¦±";
		Gotoxy(pos.X + xVal, pos.Y + yVal);
		wcout << L" ¦°" << endl;

		SetColor();
		int curmode = _setmode(_fileno(stdout), prevmode);
	}
};

