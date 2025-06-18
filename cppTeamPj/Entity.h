#pragma once

#include <string>
using std::string;

class Entity
{
public:
	// 캐릭터에 비주얼
	string objectVisual;

	// 캐릭터 이동 함수
	// abstract로 만들어서 구현 필수로 만들기
	virtual void Move() abstract;
};