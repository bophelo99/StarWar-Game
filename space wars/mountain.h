#pragma once
#include "Entity.h"

class mountain: public Entity
{
     Entity *target;
     int _type;

    public:
       mountain(Entity *_target, int type){
        target=_target;
        _type =type;
        setName("mountain");
        }
        void update(){
          sf::Vector2f _PosD = target->getDistxy(); //getPos();
          if(_type=1){
          setDist(-_PosD.x*0.3f, 0);
          if(getPos().x-width/2>width && (-_PosD.x)>0)
            {setPos(0-width/2, height/2);}
         else if(getPos().x+width/2<0 && (-_PosD.x)<0)
            {setPos(width+width/2, height/2);}
                     }
          if(_type=2){
           setDist(-_PosD.x*0.3f, 0);
          if(getPos().x-width/2>width && (-_PosD.x)>0)
            {setPos(0-width/2, height/2);}
         else if(getPos().x+width/2<0 && (-_PosD.x)<0)
            {setPos(width+width/2, height/2);}
          }
          //setPos(_Pos.x, getPos().y);
          updatePos();
        }
};

