#include "heart.hpp"
#include "drawing.hpp"

void heart::action() //this is how the heart moves on the screen.
{
    srcRect = {453, 101, 34, 36}; //srcrect of heart
    moverRect.y = (moverRect.y+5); //heart moves 5 units to right as it falls
}

heart::heart()
{
    srcRect = {453, 101, 34, 36};

    moverRect = {30, 40, 50, 50};
}

heart::heart(SDL_Rect x, SDL_Rect y):Unit(x,y){}

heart::~heart(){} //default destructor

