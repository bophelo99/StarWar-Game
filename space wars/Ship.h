#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
///#include


class Ship: public Entity
{
    private:
        int _feed;
        int _shield;
	    bool shielding=false;
	    bool shield;

    public:
        Ship();
        void advanceShip(bool);
        void advanceShipBack(bool);
        void update();
        bool isFeeded();
        void addFeed(int);
        bool isShieldActivate();
        void addShield(){_shield--;}
        void currShield(bool setShieldStatus){shielding=setShieldStatus;}
        bool isShielding()const { return shielding; }
        void deactivateshield(){shield=false;}
        int numberofSHield(){return _shield;}
        void enableShield() { shield = true;
        }




};


