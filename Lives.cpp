#include "Lives.hpp"
#include <iostream>

lives::lives()
{
    srcRect = {150, 500, 50, 50}; //initialises lives to 3 on screen
}

lives::lives(int n)
{
    srcRect = {150, 500, 50, 50};
    if (n == 1)
    {
        lifeline=1;
        moverRect = {50, 550, 50, 50};
    }
    else if (n == 2)
    {
        lifeline=2;
        moverRect = {100, 500, 50, 50};
    }
    else if (n >= 3)
    {
        lifeline=3;
        moverRect = {150, 500, 50, 50};
    }
}


void lives::action() 
{
    if (lifeline == 1)
    {
        moverRect = {50, 500, 50, 50};
    }
    else if (lifeline == 2)
    {
        moverRect = {100, 500, 50, 50};
    }
    else if (lifeline >= 3)
    {
        moverRect = {150, 500, 50, 50};
    }
}

lives::~lives(){}
