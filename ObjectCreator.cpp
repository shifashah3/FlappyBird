#include <iostream>
#include "ObjectCreator.hpp"

Unit *ObjectCreator::getObject()
{
    int random, X_POS;
    Unit* u;
    random = rand() % 100;
    X_POS = 1000 + (rand() % 100);
    if (random< 30)
    {
        SDL_Rect a = {396, 214, 14, 152}; //mid pipe
        SDL_Rect b = {X_POS,200,50,400};
        Unit * u = new pipe(a,b);
        return u;
    }

    else if (random> 60)
    {
        SDL_Rect a = {468, 178, 13, 188}; //large pipe
        SDL_Rect b = {X_POS,350,50,300};
        Unit * u = new pipe(a,b);
        return u;
    }
    else
    {
        SDL_Rect a= {320, 281, 14, 83}; //small pipe
        SDL_Rect b = {X_POS,100,50,150}; 
        Unit * u = new pipe(a,b);
        return u;
    }
    return u;
}

Unit *ObjectCreator::getCollectable(int n)
{
    int random, x_pos;
    Unit * u;
    x_pos = rand() % 1000;

    if (n==1)
    {
        SDL_Rect a = {453, 101, 34, 36};
        SDL_Rect b = {x_pos, 0, 50, 50};
        Unit * u = new heart(a,b);
        return u;
    }

    else
    {
        SDL_Rect a = {299, 68, 32, 34};
        SDL_Rect b = {x_pos, 0, 50, 50};
        Unit * u = new coins(a,b);
        return u;
    }
    return u;
}