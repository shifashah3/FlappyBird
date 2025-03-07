#include "Score.hpp"
#include "drawing.hpp"

Score Score:: operator+(int n)
{    
    Score sc;
    if (value<5)
    {
        sc.value = value +n;
    }
    else
    {
        sc.value = value;
    }
    return sc;
}

void Score:: setter(int n)
{
    value=n;
}

void Score::action()
{
    moverRect = {825, 400, 50, 50};

    if (value==0)
    {
        srcRect={306, 393, 24, 29};
    }

    if (value==1)
    {
        srcRect={347, 394, 18, 29};
    }

    if (value==2)
    {
        srcRect={391, 394, 20, 29};
    }

    if (value==3)
    {
        srcRect={432, 393, 21, 30};
    }

    if (value==4)
    {
        srcRect={474, 394, 21, 30};
    }

    if (value==5)
    {
        srcRect={307, 440, 21, 29};
    }
}


Score::Score()
{
    srcRect={306, 393, 24, 29};
    moverRect = {825, 400, 50, 50};
}

Score::~Score()
{}
