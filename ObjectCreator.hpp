#include "Unit.hpp"
#include "coins.hpp"
#include "heart.hpp"
#include "pipe.hpp"

class ObjectCreator
{
    public:
        Unit *getObject(); 
        Unit *getCollectable(int n);
};
