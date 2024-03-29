#include "Entity.h"
#include <iostream>
#include <cmath>
#include <math.h>
Entity::Entity()
{

    life = 1;
    abducting=false;
    target=false;

}

void Entity::initializer(int w, int h, Animation &_anim, int _x, int _y, float _angle, int _radius)
{
    anim = _anim;
    pos.x = _x;
    pos.y = _y;
    angle = _angle;
    radius = _radius;
    width = w;
    height = h;
}

///-----------------LIFE----------------------
void Entity::setLife(bool _life)
{
    life = _life;
}

bool Entity::getLife()
{
    return life;
}

///-----------------DIST-----------------------
void Entity::setDist(float _distx, float _disty)
{
    distxy.x = _distx;
    distxy.y = _disty;
}
void Entity::increaseDist(float _distx, float _disty, unsigned short int type)
{
    if (type == 1)
    {
        distxy.x += _distx;
        distxy.y += _disty;
    }
    else
    {
        if (type == 2)
        {
            distxy.x *= _distx;
            distxy.y *= _disty;
        }
    }
}

sf::Vector2f Entity::getDistxy()
{
    return distxy;
}

///--------------------POS---------------------
void Entity::setPos(float _x, float _y)
{
    pos.x = _x;
    pos.y = _y;
}

sf::Vector2f Entity::getPos()
{
    return pos;
}
///--------------------POS---------------------
void Entity::updatePos()
{
    pos.x += distxy.x;
    pos.y += distxy.y;
}

///--------------------ANGLE-------------------

void Entity::setAngle(float _angle)
{
    angle = _angle;
}

float Entity::getAngle()
{
    return angle;
}

void Entity::rotatexd(float rotation)
{
    angle += rotation;
    angle = fmodf(angle, 360);
    if (angle < 0)
    {
        angle += 360;
    }
}
///--------------------RADIUS------------------
float Entity::getRadius()
{
    //std::cout<<"radio a: "<<radius<<std::endl;
    return radius;
}
///--------------------NAME--------------------
void Entity::setName(std::string _name)
{
    name = _name;
}

std::string Entity::getName()
{
    return name;
}

///--------------------DRAW--------------------
void Entity::draw(sf::RenderWindow &app)
{
    anim.setPosition(pos.x, pos.y);
    anim.setRotation(angle + 90);
    if(name=="shield") {anim.rotate(rand() % 360);}
    app.draw(anim);
}

void Entity::setAnim(Animation _anim)
{
    anim=_anim;
}
void Entity::updateAnim()
{
    anim.update();
}
bool Entity::isEndAnim()
{
    return anim.isEnd();
}
