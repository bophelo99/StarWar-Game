#include "Asteroid.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Asteroid::Asteroid(Entity *target_)
{
    target=target_;
    x = rand() % 16 - 8;
    y = 1;
    while ((int)x == 0)
    {
        x = rand() % 8 - 4;
    }
    while ((int)y == 0)
    {
        y = 1;
    }

    setDist(x*0.5, y*0.5);
    setName("asteroid");
}

void Asteroid::update()
{

        sf::Vector2f _PosD = target->getDistxy();
         setDist((x*0.5)+(-_PosD.x*0.4f), y*0.5);


    sf::Vector2f _Pos = getPos();
    //updatePos();

    if (_Pos.x > width+50)
        setLife(0);
    if (_Pos.y > height+50)
         setLife(0);
    if (_Pos.x < 0-50)
         setLife(0);
    if (_Pos.y < 0-50)
         setLife(0);
        updatePos();
}
