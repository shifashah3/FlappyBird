#include <iostream>
#include "FlappyBird.hpp"

FlappyBird::FlappyBird(const FlappyBird& obj) = default;
FlappyBird& FlappyBird:: operator= (const FlappyBird& obj) = default;

void FlappyBird::drawObjects()
{
    drawScore(); //draws score
    health->draw(); //draws lives

    if (bdraw==false)
    {
        obj_bird ->draw(); //draws bird

        for(lives* l:lifelines)
        {  
            l->draw();
        }
        drawScore();
        health->draw();
    }


    if (life_count==0)
    {
        running = false;
    }
    if(score_count==5)
    {
        running = false;
        gamestate = true;
    }
    if (life_count>=3)
    {
        life_count=3;
    }
    //drawing objects
    for(Unit* p: pipes)
    {  
        p->draw();
    }

    for(Unit* h:hearts)
    {  
        h->draw();
    }

    for(Unit* c:coin)
    {  
        c->draw();
    }

    for(Unit* c: coin)
    {
        if(*obj_bird == c) //sees if bird collects coins
        {
            if(running==true){
                c->setMover(0,700);
                score_count +=1;
                music=Mix_LoadMUS("coin.wav"); //sound effect for coin collection
                Mix_PlayMusic(music,0); 
                scores->setter(score_count); //setter func for which srcRect score to draw
                drawScore();
                cout<<"coin collected"<<endl;
            }
        }
    }

    for(Unit* h: hearts) //sees if bird collects hard
    {
        if(*obj_bird == h)
        {
            if(running==true){
                h->setMover(0,700); 
                life_count +=1;
                health->setter(life_count);
                health->draw();
                music=Mix_LoadMUS("inc.wav"); //heart inc sound effect
                Mix_PlayMusic(music,0);

                cout<<"heart caught"<<endl;
            }
        }
    }

    for(Unit* p: pipes)
    {
        if(*obj_bird == p) //checks for collison between pipes and bird.
        {
            if(running==true){
                obj_bird->setMover(0,0);
                life_count -=1;
                music=Mix_LoadMUS("minuslife.wav");//collison sound effect
                Mix_PlayMusic(music,0);
                health->setter(life_count);
                health->draw();
                cout<<"pipe collision"<<endl;
            } 
        }
    }
}

void FlappyBird::createObject(int x, int y)
{
    //probabilty of an object being created i.e. how frequently smth comes in the game
    int prob;
    prob= rand()%100;

    if (prob%2==0)
    {
        pipes.push_back(obj.getObject());
    }

    if (prob%3==0)
    {
        coin.push_back(col.getCollectable(2));
    }

    if (prob%8==0)
    {
        hearts.push_back(col.getCollectable(1));
    }
}

void FlappyBird::createObject()
{
    lives* l1= new lives(1);

    lifelines.push_back(l1);
}

void FlappyBird::createObject(int x)
{
    if (x==0){
        obj_bird = new bird((SDL_Rect){14, 229, 93, 60}, (SDL_Rect){121, 240, 89, 50},(SDL_Rect){224, 236, 85, 59});     
    }
    else if ( x==1){
        obj_bird = new bird((SDL_Rect){10, 40, 80, 61}, (SDL_Rect){ 101, 37, 83, 51},(SDL_Rect){ 205, 35, 84, 66});
    }
    else if (x==2){
        obj_bird = new bird((SDL_Rect){ 224, 131, 75, 54}, (SDL_Rect){ 116, 150, 75, 31},(SDL_Rect){ 6, 152, 74, 55} );
    }
}

void FlappyBird::drawScore()
{ 
    scores->draw(); 
}

FlappyBird::~FlappyBird() //deletes dynamic objects
{
    delete obj_bird;
    obj_bird = nullptr;

    delete scores;
    scores = nullptr;

    delete health;
    health = nullptr;

    Mix_FreeMusic(music);
    music = nullptr;
    
    Mix_Quit();

    for (list<Unit *>::iterator i = hearts.begin(); i != hearts.end(); i++)
    {
        delete (*i);
        hearts.erase(i);
    }

    for (list<Unit *>::iterator i = coin.begin(); i != coin.end(); i++)
    {
        delete (*i);
        coin.erase(i);
    }

    for (list<Unit *>::iterator i = pipes.begin(); i != pipes.end(); i++)
    {
        delete (*i);
        pipes.erase(i);
    }

    for (list<lives *>::iterator i = lifelines.begin(); i != lifelines.end(); i++)
    {
        delete (*i);
        lifelines.erase(i);
    }
}

FlappyBird::FlappyBird(){}

bool FlappyBird::getstate() //gets game state to check if bird should move or not.
{
    if (running == true)
    {
        return false;
    }
    else{
        return true;
    }
}

void FlappyBird::gameend() //conditions for the end of game
{
    if (running == false && gamestate == true)
    {
        // music=Mix_LoadMUS("won.wav");
		// Mix_PlayMusic(music,0);
        gamewon* won = new gamewon();
        won->draw();
    }

    else if (running == false && gamestate == false)
    {
        // music=Mix_LoadMUS("lost.wav");
		// Mix_PlayMusic(music,0);        
        gameover* lost = new gameover();
        lost->draw();
    }
}
