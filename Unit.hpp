#include<SDL.h>
#include <iostream>
#include "drawing.hpp"
#pragma once
using namespace std;

//This class handles the drawing functions & is also inherited by most of the other classes specifically the object classes.
class Unit
{
protected:
    SDL_Rect srcRect, moverRect; //protected so that inherited classes can use these attributes.

public:
    void draw(); 
    virtual void action() = 0; //pure virtual becuse this is how an object appers to moves on the screen and is different for every object & there is no definition for this function in this class.
    Unit();
    Unit(SDL_Rect a, SDL_Rect b);
    SDL_Rect* getMover(); //getter func that returns the moverrect that is then used to check for collisions w/ pipes coins hearts.
    virtual ~Unit(); //virtual destructor, so that inherited 
    void setMover(int xc, int yc); //setter func for mover
};
