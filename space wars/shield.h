#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class shield: public Entity
{
     Entity *target;

    public:
        shield(Entity *_target){
        target=_target;
        setName("shield");
        }
        void update(){

          sf::Vector2f _Pos = target->getPos();
          setPos(_Pos.x, _Pos.y);
          updatePos();
        }

};
