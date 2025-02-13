#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <math.h>
const double MATH_PI = std::atan(1)*4;

class Entity
{   private:
        float angle;
        float radius;
        sf::Vector2f distxy;
        bool life;
        std::string name;
        sf::Vector2f pos;
        Animation anim;
        bool abducting;
        bool target;

       // Entity* targetUpdate_;
    protected:
        //int width, height;
    public:

        int width, height;
        Entity();
        bool isEndAnim();
        void updateAnim();
        void setAnim(Animation);
        ///--------------------------------------------
        void initializer(int w, int h,Animation &_anim, int _x,int _y, float _angle=0,int _radius=1);
        ///--------------------------------------------
        void setLife(bool _life);
        bool getLife();
        ///--------------------------------------------
        float getRadius();
        ///--------------------------------------------
        void setPos(float,float);
        sf::Vector2f getPos();
        ///--------------------------------------------
        void setDist(float,float);
        void increaseDist(float,float,unsigned short int=1);
        sf::Vector2f getDistxy();
        ///--------------------------------------------
        void setAngle(float);
        float getAngle();
        void rotatexd(float);
        ///--------------------------------------------
        void setName(std::string);
        std::string getName();
        ///--------------------------------------------
        virtual void update(){};
        void draw(sf::RenderWindow &app);
        ///--------------------------------------------
        void updatePos();
/*
        void targetUpdate(Entity* updateTarget)
        {
            targetUpdate_=updateTarget;
        }

        Entity* gettarget(){return targetUpdate_;}
*/
        void abduct(bool State){abducting=State;}
        bool isAbducted(){return abducting;}

        void istargeted(bool state) {target=state;}
        bool istarget(){return target;}

};


