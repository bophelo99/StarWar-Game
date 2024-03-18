#include "EnemyShip.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
EnemyShip::EnemyShip(Entity *_target)
{
    target = _target;
    pointingTarget = false;
    setName("enemy");
    bulletCoolDown = 0;
    shooting = true;
    srand(time(0));
    randomState=rand()%2;
}

void EnemyShip::update()
{
     shooting = false;
   delay++;
   if(delay%500==0){randomState=rand()%2;}
   //std::cout<<randomState<<"\n";
    if(isAbducted()) ///enemy tries to escape with humanoid and attack the player by shooting
   {
       sf::Vector2f _PosD = target->getDistxy();
       setDist(-_PosD.x*0.7f,-2);///when the enemy collide with humanoid it wiil try to escape moving up
      setAngle(270);
       updatePos();
   }/*
    if(randomState==1 && !isAbducted() && istarget())  ///tries to steal the humanoid
    {
        std::cout<<randomState<<"\n";
        hold=gettarget();
            sf::Vector2f _Pos = getPos(), targetPos = hold->getPos();
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
            sf::Vector2f _PosD = target->getDistxy();

            increaseDist(cos(getAngle() * (MATH_PI / 180)) * 2 + (-_PosD.x*0.7f), sin(getAngle() * (MATH_PI / 180)) * 2);
            int maxSpeed = 2;
            float speed = sqrt(getDistxy().x * getDistxy().x + getDistxy().y * getDistxy().y);
            if (speed > maxSpeed)
            {
                increaseDist(maxSpeed / speed, maxSpeed / speed, 2);
            }

            updatePos();

            if (_Pos.x > width+50)
                setLife(0);
            if (_Pos.y > height +50)
                setLife(0);
            if (_Pos.x < -50)
                setLife(0);
            if (_Pos.y < -50)
                setLife(0);


            if (pointingTarget)
            {
                if (bulletCoolDown % 8 == 0)
                {
                    shooting = false;
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
    }*/
    else{

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
            sf::Vector2f _PosD = target->getDistxy();
           // setDist(-_PosD.x*0.7f, 0);

            increaseDist(cos(getAngle() * (MATH_PI / 180)) * 0.2 + (-_PosD.x*0.7f), sin(getAngle() * (MATH_PI / 180)) * 0.2);
            int maxSpeed = 2;
            float speed = sqrt(getDistxy().x * getDistxy().x + getDistxy().y * getDistxy().y);
            if (speed > maxSpeed)
            {
                increaseDist(maxSpeed / speed, maxSpeed / speed, 2);
            }

            updatePos();

            if (_Pos.x > width+50)
                setLife(0);
            if (_Pos.y > height +50)
                setLife(0);
            if (_Pos.x < -50)
                setLife(0);
            if (_Pos.y < -50)
                setLife(0);

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

}

bool EnemyShip::isShooting()
{
    return shooting;
}

