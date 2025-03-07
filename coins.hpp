#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class coins : public Unit
{
    private:
        int obj_state = 0; // the object has 6 different states this will be update continuously to represent them.
        bool fall = true; 
    
    public:
        void action(); // this will deal with the change in x and/or y coordinates.
        coins(); // will initialise srcrect and moverrect
        coins(SDL_Rect x, SDL_Rect y); // overloaded constructor that initialises the x and y values of moverrect with the passed values.
        ~coins(); //default constructor
};
