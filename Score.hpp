#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class Score : public Unit
{
    private:
    int value = 0;

    public:
    void action();
    void setter(int n);
    Score operator +(int n); //operator overloading for ++
    Score();
    ~Score();
};