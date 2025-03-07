#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class heart : public Unit
{
    private:

    public:
        void action(); // this will deal with the change in x and/or y coordinates.
        heart(); // initialises the srcrect
        heart(SDL_Rect x, SDL_Rect y); // overloaded constructor that initialises the x and y values of moverrect with the passed values.
        ~heart(); //default destructor
};