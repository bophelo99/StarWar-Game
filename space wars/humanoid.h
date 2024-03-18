#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

class humanoid: public Entity
{
     Entity *target, *target2;

    public:
       humanoid(Entity *_target, int width_, int height_ ){
        target=_target;
        height=height_;
        width=width_;
        setName("humanoid");
        srand(time(0));
        setPos(rand()%(static_cast<int>((width-50)-(50)+1))+50, rand()%(static_cast<int>((height-100)-(height-200)+1))+(height-200));
        }
        void update(){
          sf::Vector2f _PosD = target->getDistxy();
          setDist(-_PosD.x*0.7f, 0);
          if(getPos().x<0 || getPos().x>width || getPos().y>height)
            setLife(0);/*
          if(isAbducted() && istarget())
          {
              target2=gettarget();
              sf::Vector2f _Pos = target2->getPos();
              setPos(_Pos.x-20, _Pos.y);
          }
          if(isAbducted() && !istarget())
          {
              sf::Vector2f _Pos = target2->getPos();
              increaseDist(0,-2);
          }*/


          updatePos();
        }
};
