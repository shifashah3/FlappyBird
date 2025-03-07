#include<SDL.h>
#include <iostream>
#include <vector>
#include "Unit.hpp"
#pragma once
using namespace std;

class pipe : public Unit
{
public:
    void action();
    pipe(SDL_Rect a, SDL_Rect b);
    pipe();
    ~pipe();
};