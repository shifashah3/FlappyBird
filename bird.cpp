#include "bird.hpp"
#include <iostream>

using namespace std;

// void bird::action()
// {
//     if(obj_state==0){
//         srcRect = (SDL_Rect){14, 229, 93, 60}; //bird in up position    
//     }
//     else if(obj_state==1){
//         srcRect = (SDL_Rect){121, 240, 89, 50}; //bird in mid position
//     }
//     else if(obj_state==1){
//         srcRect = (SDL_Rect){224, 236, 85, 59}; //bird in down position
//     }
//     obj_state = (obj_state+1)%3; //modulus by 3 bcz only 3 orientation of the bird's wings, so it returns to 0 when it reaches 3
// }

void bird::action()
{
    if(obj_state==0){
        srcRect = srcRect_up; //bird in up position    
    }
    else if(obj_state==1){
        srcRect = srcRect_middle; //bird in mid position
    }
    else if(obj_state==1){
        srcRect = srcRect_down; //bird in down position
    }
    obj_state = (obj_state+1)%3; //modulus by 3 bcz only 3 orientation of the bird's wings, so it returns to 0 when it reaches 3
}


bird::bird(SDL_Rect up, SDL_Rect middle, SDL_Rect down)
{
    srcRect_up=up;
    srcRect_middle=middle;
    srcRect_down=down;
    srcRect=up;
    moverRect ={0, 300, 75, 50};
}

// bird::bird()
// {
//     srcRect = {6, 226, 92, 59};
//     moverRect = {0, 300, 75, 50};
// }


void bird::handleMove(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN) //tracks which key is pressed
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            up = true;
            // cout << "up" << endl; //to track in terminal which key is pressed
            break;
        case SDLK_DOWN:
            down = true;
            // cout << "down" << endl;
            break;
        case SDLK_LEFT:
            // cout << "left" << endl;
            left = true;
            break;
        case SDLK_RIGHT:
            right = true;
            // cout << "right" << endl;
            break;
        }
    }
    else if (e.type == SDL_KEYUP) //tracks when key is released
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            up = false;
            break;
        case SDLK_DOWN:
            down = false;
            break;
        case SDLK_LEFT:
            left = false;

            break;
        case SDLK_RIGHT:
            right = false;
            break;
        }
    }
    if (right) //change in coords wrt keys, basically moves the bird in respective direction, also effects bird's speed.
    {
        moverRect.x += 10;
    }
    if (left)
    {
        moverRect.x -= 10;
    }

    if (up)
    {
        moverRect.y -= 10;
    }
    if (down)
    {
        moverRect.y += 10;
    }

    if (moverRect.x <= 0) //so that bird doesn't go out of screen, don't want to loop it from left
    {
        moverRect.x = 0;
    }

    else if (moverRect.x >= 1000) //so that bird loops from right to left
    {
        moverRect.x = 0;
    }

    if (moverRect.y <= 0) //so that bird doesn't go out of screen, don't want to loop it from up/down
    {
        moverRect.y = 0;
    }

    else if (moverRect.y >= 500)//so that bird doesn't go out of screen, don't want to loop it from up/down
    {
        moverRect.y = 500;
    }
}

bool bird::operator==(Unit* u){
    return SDL_HasIntersection(u->getMover(), this->getMover());
}

bird::~bird(){} //default destructor
