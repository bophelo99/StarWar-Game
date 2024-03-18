#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>



class EnemyShip: public Entity
{
    Entity *target;
    bool pointingTarget;
    int bulletCoolDown;
    bool shooting;
    int delay;
    int randomState;
    Entity* hold;


    public:
        EnemyShip(Entity *_target);
        void update();
        bool isShooting();


};


