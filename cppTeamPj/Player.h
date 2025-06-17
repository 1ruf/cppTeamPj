#pragma once
#include"Entity.h"

#include<iostream>
class Player : public Entity
{
private:
    int life { 0 };
public:
    Player(const string& visual)
    {
        objectVisual = visual;
    }

    void Move() override
    {
        std::cout << "ASD";
    }
};

