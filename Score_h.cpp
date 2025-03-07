#include "Score_h.hpp"
#include "drawing.hpp"

void  Score_h :: operator+(int n)
{
    if (value<3)
    {
        value = value +n;
    }
    else
    {
        value = 3;
    }
}

void Score_h :: setter(int n)
{
    value=n;
}

void Score_h ::action()
{
    moverRect = {125, 400, 50, 50};

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

    if (value>=3)
    {
        value=3;
        srcRect={432, 393, 21, 30};
    }

}

Score_h ::Score_h()
{
    srcRect={306, 393, 24, 29};
    moverRect = {125, 400, 50, 50};
}

Score_h ::~Score_h(){}