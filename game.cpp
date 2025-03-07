#include "game.hpp"
#include <iostream>
#include <stack>
#include "Unit.hpp"
using namespace std;

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if(Drawing::gRenderer == NULL )
			{
				printf( "Renderer SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("assets2.png");
    // gTexture = loadTexture("homescreen.jpg");
	gTexture = loadTexture("home.png");
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	// music = Mix_LoadMUS("bgm.mp3");
	// if (music == NULL)
    // {
    //     printf("Unable to load music: %s \n", Mix_GetError());
    //     success = false;
    // }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	Mix_FreeMusic(music);
    music = NULL;
    
    Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		m_width = loadedSurface->w;
        m_height = loadedSurface->h;

		if(newTexture == NULL)
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::run()
{

	FlappyBird flappyobj;

    while (!check)
    {
        SDL_RenderCopyEx(Drawing::gRenderer, gTexture, NULL, NULL, 0, 0, SDL_FLIP_NONE);
        SDL_RenderPresent(Drawing::gRenderer);
        int xMouse, yMouse;

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
                cout << xMouse << " & " << yMouse << endl;

				if (xMouse>210 and xMouse<250 and yMouse>270 and yMouse<350){
					character = 0; // Orange Bird
				}

				else if (xMouse>470 and xMouse<530 and yMouse>270 and yMouse<350){
					character = 1; // Blue Bird
				}

				else if (xMouse>750 and xMouse<800 and yMouse>270 and yMouse<350){
					character = 2; // Brown Bird
				}

				if (xMouse > 0 && yMouse > 0)
                {
                    quit = false;
                    check = true;
					play= true;
                    gTexture = loadTexture("background.png");
				
					Mix_PlayMusic(music,-1);
                }

                if (xMouse > 1045 && xMouse < 1165 && yMouse > 164 && yMouse < 253)
                {
                    quit = true;
                    check = true;
                }
            }
        }
    }
	flappyobj.createObject(character);

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

			else if(e.type == SDL_KEYDOWN)
			{
				switch(e.key.keysym.sym)
				{
					case SDLK_p:
						if (!Mix_PlayingMusic())
							Mix_PlayMusic(music, -1);

						else if (Mix_PausedMusic())
							Mix_ResumeMusic();

						else
							Mix_PauseMusic();

						break;

					case SDLK_s:
						Mix_HaltMusic();
						break;	
				}
			}

            if (isgameover == false)
            {
				flappyobj.obj_bird->handleMove(e);
				isgameover=flappyobj.getstate();
            }
        }

		//creating the screen moving effect: Here, scrollingOffset is decreased by 6 in each iteration of the loop, creating a horizontal scroll. When scrollingOffset becomes less than the negative of the image width (-m_width), it is reset to 0, creating a continuous loop effect.
		// The two SDL_RenderCopyEx calls are used to render the background texture (gTexture) twice, side by side, to ensure a seamless loop.
        scrollingOffset -= 6;
        if (scrollingOffset < -m_width)
        {
            scrollingOffset = 0;
        }

        SDL_RenderClear(Drawing::gRenderer);

        SDL_Rect renderQuad = (SDL_Rect){scrollingOffset, 0, m_width, m_height};
        SDL_RenderCopyEx(Drawing::gRenderer, gTexture, NULL, &renderQuad, 0, 0, SDL_FLIP_NONE);

        renderQuad = {scrollingOffset + m_width, 0, m_width, m_height};
        SDL_RenderCopyEx(Drawing::gRenderer, gTexture, NULL, &renderQuad, 0, 0, SDL_FLIP_NONE);


		int a ;
		a =rand()%100; //random number generated for probability calculation
		if (a<=20 && play == true)
		{
			if (create ==true)
			{
				flappyobj.createObject();
				create = false;
			}
			
			delay--;
			if (delay==0)
			{	
				int xx = 1 + (rand() % 955);
				delay = 5;
				flappyobj.createObject(xx, 5);
			}
			create = false;
		}

		if (isgameover == true)
		{
			// cout<<__LINE__<<": in intersected if() \n";
			flappyobj.gameend();
		}

        flappyobj.drawObjects();

        SDL_RenderPresent(Drawing::gRenderer);

        SDL_Delay(40);
    }
}