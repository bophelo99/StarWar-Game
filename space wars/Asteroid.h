#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <time.h>

class Asteroid: public Entity
{
     Entity *target;
     float x, y;

    public:
        Asteroid( Entity *target);
        void update();

};

