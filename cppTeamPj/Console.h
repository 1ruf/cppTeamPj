#pragma once
#include<iostream>
using std::cout;
using std::wcout;
using std::endl;
#include<string>
using std::string;
using std::wstring;
#include<Windows.h>

void SetConsoleSettings(int _width, int _height, bool _isFullScreen, const std::wstring& _title);
void SetLockResize();
COORD GetConsoleResolution();


void Gotoxy(int _x, int _y);
BOOL IsGotoxy(int _x, int _y);
COORD CursorPos();
void SetCursorVisual(bool _isVis, DWORD _size);
enum class COLOR
{
    BLACK, BLUE, GREEN, SKYBLUE, RED,
    VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
    LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
    LIGHT_YELLOW, WHITE, END
};
void SetColor(COLOR _textcolor = COLOR::WHITE, COLOR _bgcolor = COLOR::BLACK);
void FrameSync(unsigned int _frame);
void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight);