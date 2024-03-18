#pragma once
#include "Entity.h"

class mine: public Entity
{
     Entity *target;

    public:
        mine(Entity *_target){
        target=_target;
        setName("mine");
        }
        void update(){
          sf::Vector2f _PosD = target->getDistxy(); //getPos();
          setDist(-_PosD.x*0.5f, 0);
          if(getPos().x<0 || getPos().x>width)
            setLife(0);
          //setPos(_Pos.x, getPos().y);
          updatePos();
        }
};
