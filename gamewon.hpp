#include<SDL.h>
#include "Unit.hpp"
#pragma once

class gamewon: public Unit
{
    public:
        gamewon();
        void action();
        ~gamewon();
};