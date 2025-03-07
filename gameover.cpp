#include "gameover.hpp"
#include <iostream>

gameover::gameover()
{
    srcRect = {91, 323, 112, 76}; //srcRect for to display game over when player loses
}

void gameover::action()
{
    moverRect = {350,150,250,250};
}

gameover::~gameover(){} //default destructor
