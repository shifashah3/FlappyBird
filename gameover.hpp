#include<SDL.h>
#include "Unit.hpp"
#pragma once

class gameover: public Unit
{
    public:
        gameover(); 
        void action();
        ~gameover();
};