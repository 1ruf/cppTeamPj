#pragma once

#include <string>
using std::string;

class Entity
{
public:
	// ĳ���Ϳ� ���־�
	string objectVisual;

	// ĳ���� �̵� �Լ�
	// abstract�� ���� ���� �ʼ��� �����
	virtual void Move() abstract;
};