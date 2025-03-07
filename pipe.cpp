#include "pipe.hpp"
#include "drawing.hpp"

void pipe::action()
{
    moverRect.x -= 5;
}


pipe::pipe()
{
    srcRect = {468, 178, 13, 188}; //large pipe
    moverRect = {10,10,20,200};
}

pipe::pipe(SDL_Rect a, SDL_Rect b): Unit(a, b){}

pipe::~pipe(){}

