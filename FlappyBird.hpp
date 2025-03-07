#include<SDL.h>
#include <SDL_mixer.h>
#include "bird.hpp"
#include "Score.hpp"
#include "Score_h.hpp"
#include "coins.hpp"
#include "heart.hpp"
#include "Lives.hpp"
#include "pipe.hpp"
#include "gamewon.hpp"
#include "gameover.hpp"
#include "ObjectCreator.hpp"
#include<list>

using namespace std;

class FlappyBird
{
    private:
        SDL_Renderer *gRenderer;
        SDL_Texture *assets;

        ObjectCreator obj;
        ObjectCreator col;

        bool bdraw=false;
        bool running = true;
        bool gamestate= false;

        int life_count = 3;
        int score_count = 0;
        
        Mix_Music* music=nullptr;

        list<Unit*> hearts;
        list<Unit*> coin;
        list<Unit*> pipes;
        list<lives*> lifelines;

        Score * scores = new Score();
        Score_h * health = new Score_h();

    public:
        bird* obj_bird; 

        FlappyBird();
        ~FlappyBird();  //destructor to delete all dynamic objects
        //making assignment op overload & copy ctor to implement Rule of Three
        FlappyBird(const FlappyBird& obj);
        FlappyBird& operator= (const FlappyBird& obj);
        void drawObjects(); 
        void createObject(int, int); //creates pipes object and pushes into list
        void createObject(int); //chooses which bird's srcrect to pass into bird class
        void createObject(); //creates heart and coin
        void drawScore(); //draws score which inc with inc in coins
        bool getstate(); //retuns true or false which then checks if bird should move
        void gameend(); //decides which asset to draw depending on state.
};