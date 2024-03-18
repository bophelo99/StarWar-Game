#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <time.h>

class BomberShip: public Entity
{
    private:
       enum class objectsDirection
       {
            UP=0,
            DOWN,
            LEFT,
            RIGHT,
            NONE
        };
        objectsDirection major_direction_;
        objectsDirection movementDirection_;
        double slope_;
        bool turningPointAvailable_;
        sf::Vector2f turningPoint;
        int timer_;

       unsigned long int time_;

    public:
        BomberShip(int width_, int height_);
        void move(), moveup(), movedown();
        void slope();
        void update();


};
