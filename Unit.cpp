#include "Unit.hpp"
#include <iostream>
using namespace std;

Unit :: Unit()
{

}
SDL_Rect* Unit::getMover() //returns the moverRect of the object
{
    return &moverRect;
}

Unit :: Unit(SDL_Rect a ,SDL_Rect b)
{
    srcRect = a;
    moverRect = b;
}

void Unit :: draw()
{
    action();
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect); //this calling SDL's own function that makes the asset appear on the screen
}

void Unit:: setMover(int xc, int yc)
{
    moverRect.x = xc;
    moverRect.y = yc;
}


Unit :: ~Unit() //virtual destructor
{}


