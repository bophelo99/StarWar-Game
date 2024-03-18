#pragma once
#include "Entity.h"

class cloud: public Entity
{
     Entity *target;

    public:
       cloud(Entity *_target){
        target=_target;
        setName("cloud");
        }
        void update(){
          sf::Vector2f _PosD = target->getDistxy();
          setDist(-_PosD.x*0.5f, 0);
          if(getPos().x-width/2>width && (-_PosD.x)>0)
            {setPos(0-width/2, height/2);}
         else if(getPos().x+width/2<0 && (-_PosD.x)<0)
            {setPos(width+width/2, height/2);}
          updatePos();
        }
};
