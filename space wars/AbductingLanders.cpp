#include "AbductingLanders.h"
#include <iostream>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>

 void abductLander::update()
 {
   delay++;
   if(delay%500==0){randomState=rand()%2;}
   std::cout<<randomState<<"\n";
  /* if(target2->getLife() && randomState==0 && !(target2->isAbducted())) ///enemy tires to abduct the humanoid and shoot player
   {
       ///move towards the humanoid and if collided
   }
   else if(randomState==1 && !(target2->isAbducted()))///enemy tries to attack player by shooting
   {
    sf::Vector2f _Pos = getPos(), targetPos = target->getPos();
    sf::Vector2f coso = targetPos - _Pos;
    float angle2 = (atan2(coso.x, coso.y) * (180 / MATH_PI));


    angle2 = fmodf(angle2, 360);

    angle2 = -angle2 - 270;

    float fgetAngle = fmodf(getAngle(), 360);

    if (angle2 < 0)
    {
        angle2 += 360;
    }
    if (fgetAngle < 0)
    {
        fgetAngle += 360;
    }

    float dif = (angle2)-fgetAngle;
    dif = fmodf(dif, 360);

    if (!((dif >= 358.5f && dif <= 360.0f) || (dif >= 0.0f && dif <= 1.5f)))
    {
        pointingTarget = false;
        if ((dif > 0 && dif < 180))
        {
            rotatexd(3);
        }
        else
        {
            rotatexd(-3);
        }
    }
    else
    {
        pointingTarget = true;
    }

    increaseDist(cos(getAngle() * (MATH_PI / 180)) * 0.2, sin(getAngle() * (MATH_PI / 180)) * 0.2);
    int maxSpeed = 1;
    float speed = sqrt(getDistxy().x * getDistxy().x + getDistxy().y * getDistxy().y);
    if (speed > maxSpeed)
    {
        increaseDist(maxSpeed / speed, maxSpeed / speed, 2);
    }

    updatePos();

    if (_Pos.x > width)
        setPos(0, _Pos.y);
    if (_Pos.y > height )
        setPos(_Pos.x, 0);
    if (_Pos.x < 0)
        setPos(width, _Pos.y);
    if (_Pos.y < 0)
        setPos(_Pos.x, height);

    if (pointingTarget)
    {
        if (bulletCoolDown % 8 == 0)
        {
            shooting = true;
        }
        else
        {
            shooting = false;
        }
        bulletCoolDown++;
    }
    else
    {
        bulletCoolDown++;
        shooting = false;
    }
    if (bulletCoolDown == 1000)
        bulletCoolDown = 0;
   }
   else if(target2->isAbducted()) ///enemy tries to escape and attack the player by shooting
   {
       ///when the enemy collide with humanoid it wiil try to escape

   }

*/
 }
