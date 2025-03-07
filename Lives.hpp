#include<SDL.h>
#include "Unit.hpp"
#pragma once

class lives: public Unit
{
    private:
        int lifeline = 3;

    public:
        lives();
        lives(int n);
        void action();
        ~lives();
};