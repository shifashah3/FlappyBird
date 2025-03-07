#include <SDL.h>
#include "Unit.hpp"
#include "coins.hpp"
#include "heart.hpp"
#include "pipe.hpp"
#pragma once

class bird: public Unit
{
private:
    int obj_state = 0; //orientation of the bird's wings
    //bool function for movement direction set to false, will turn true when keys pressed
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    SDL_Rect srcRect_up;
    SDL_Rect srcRect_middle;
    SDL_Rect srcRect_down;


public:
    // bird(); //will be initialised with srcrect and moverrect
    bird(SDL_Rect up, SDL_Rect middle, SDL_Rect down); //will be initialised with srcrect and moverrect
    void handleMove(SDL_Event &e); //this handles the movement of the bird in regards to which arrow key is pressed
    ~bird(); //default destructor
    void action(); //defines how the bird moves
    bool operator==(Unit* u);
};