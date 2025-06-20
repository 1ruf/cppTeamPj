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

void RenderBox(int curIndex);

Menu TitleSceneInput();


class SelectBar
{
private:
	int _width = 13;
	int _height = 3;
public:
	SelectBar(int width = 15,int height = 5) 
	{ 
		_width = width;
		_height = height;
	}
	void Draw(COORD pos, COLOR textColor = COLOR::WHITE, COLOR bgColor = COLOR::BLACK);
	void Erase(COORD pos);
};

