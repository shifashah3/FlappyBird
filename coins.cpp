#include "coins.hpp"
#include "drawing.hpp"

void coins::action() //this is how the coin moves on the screen.
{
    if (obj_state == 0)
    {
        srcRect = {299, 68, 32, 34}; //coin 1
    }
    else if (obj_state == 1)
    {
        srcRect = {333, 68, 28, 35}; //coin 2
    }
    else if (obj_state == 2)
    {
        srcRect = {366, 69, 15, 34}; //coin 3
    }
    else if (obj_state == 3)
    {
        srcRect = {313, 108, 7, 34}; //coin 4
    }
    else if (obj_state == 4)
    {
        srcRect = {333, 108, 16, 34}; //coin 5
    }
    else if (obj_state == 5)
    {
        srcRect = {355, 108, 28, 34}; //coin 6
    }
    
    moverRect.y = (moverRect.y+5); //as the coins fall they move 5 units to right
    
    obj_state = (obj_state+1)%6; //modulus by 6 bcz only 6 orientation of the coin, so it returns to 0 when it reaches 6
}

coins::coins()
{
    srcRect = {299, 68, 32, 34}; //coin1

    moverRect = {0, 40, 50, 50};
}

coins::coins(SDL_Rect x, SDL_Rect y):Unit(x,y){}

coins::~coins(){}