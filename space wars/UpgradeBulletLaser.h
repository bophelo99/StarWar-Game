#pragma once
#include "Entity.h"


class Coso: public Entity
{
     Entity *target;

    public:
        Coso(Entity *_target){
        target=_target;
        setName("coso++");
        }
        void update(){
          sf::Vector2f _PosD = target->getDistxy();
          setDist(-_PosD.x*0.4f, 0);
          if(getPos().x<0 || getPos().x>width)
            setLife(0);
          updatePos();
        }
};
