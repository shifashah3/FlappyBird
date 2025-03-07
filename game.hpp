#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "bird.hpp"
#include "FlappyBird.hpp"
#pragma once

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 500;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    SDL_Event e;

    bool check = false;
    bool quit = true;
    bool play = false;
    int delay = 20;
    bool create = true;

    int m_width;
    int m_height;

    int scrollingOffset = 0;
    bool isgameover = false;

    SDL_Renderer *gRenderer = NULL;
    SDL_Texture *assets = NULL;

    //Mix_Music *bgm = NULL;
    Mix_Music *music = NULL;

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    int character;
};

