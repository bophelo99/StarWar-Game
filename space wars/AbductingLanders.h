#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

class abductLander: public Entity
{
    bool pointingTarget;
    int bulletCoolDown;
    bool shooting;
    int delay;
    int randomState;
    bool toggle;



    public:
        abductLander()
        {
           pointingTarget = false;
           setName("abductingenemy");
           bulletCoolDown = 0;
           shooting = true;
           srand(time(0));
           randomState=rand()%1;
        }
        void update();
        void updateHumanoidtargetState(bool state_)
        {
            toggle=state_;
        }
        bool isShooting(){return shooting;}

};
