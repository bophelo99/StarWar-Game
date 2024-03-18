#include "Ship.h"
#include <iostream>
Ship::Ship()
{
    setName("player");
    _feed = 0;
    _shield=3;
	shielding = false;
	shield = false;
}

void Ship::advanceShip(bool _move)
{
    if (_move)
    {
        increaseDist(cos(getAngle() * (MATH_PI / 180)) * 0.2, sin(getAngle() * (MATH_PI / 180)) * 0.2);
    }
    else
    {
        setDist(getDistxy().x * 0.975, getDistxy().y * 0.975);
    }

    int maxSpeed = 16;
    float speed = sqrt(getDistxy().x * getDistxy().x + getDistxy().y * getDistxy().y);
    if (speed > maxSpeed)
    {
        increaseDist(maxSpeed / speed, maxSpeed / speed, 2);
    }
}

void Ship::advanceShipBack(bool _move)
{

    if (_move)
    {
        increaseDist(-cos(getAngle() * (MATH_PI / 180)) * 0.2, -sin(getAngle() * (MATH_PI / 180)) * 0.2);
    }
    else
    {
        setDist(getDistxy().x * 0.975, getDistxy().y * 0.975);
    }

    int maxSpeed = 16;
    float speed = sqrt(getDistxy().x * getDistxy().x + getDistxy().y * getDistxy().y);
    if (speed > maxSpeed)
    {
        increaseDist(maxSpeed / speed, maxSpeed / speed, 2);
    }
}

void Ship::update()
{
    //updatePos();
    //sf::Vector2f _Pos = getPos();
    if(getPos().x+getDistxy().x > 50 && getDistxy().x<=0 && getPos().y+getDistxy().y > 50 && getDistxy().y<=0)
    {
        updatePos();
    }
    else if(getPos().x+getDistxy().x<1150 && getDistxy().x>=0 && getPos().y+getDistxy().y < 550 && getDistxy().y>=0)
    {
        updatePos();
    }
    else if(getPos().x+getDistxy().x > 50 && getDistxy().x<=0 && getPos().y+getDistxy().y < 550 && getDistxy().y>=0)
    {
        updatePos();
    }
    else if(getPos().x+getDistxy().x<1150 && getDistxy().x>=0 && getPos().y+getDistxy().y > 50 && getDistxy().y<=0)
    {
        updatePos();
    }
    /*sf::Vector2f _Pos = getPos();
    if (_Pos.x > width-51 )
        setPos(width-51-16, _Pos.y);
    if (_Pos.y > height-51 )
        setPos(_Pos.x, height-51-16);
    if (_Pos.x < 51)
        setPos(51+16, _Pos.y);
    if (_Pos.y < 51)
        setPos(_Pos.x,51+16);*/
}
bool Ship::isFeeded()
{
    return _feed > 0;
}

bool Ship::isShieldActivate()
{
    return (_shield>0 & shield);
}

void Ship::addFeed(int feed)
{
    _feed+=feed;
}


