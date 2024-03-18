#include "BomberShip.h"
#include <iostream>
#include <ctime>
#include <cmath>


BomberShip::BomberShip(int width_, int height_)
:turningPointAvailable_{false}
{

    setName("BomberShip");
    height=height_;
    width=width_;
    srand(time(0));
    time_=0;
    movementDirection_ = objectsDirection::DOWN;
    major_direction_ = objectsDirection::RIGHT;///static_cast<objectsDirection>(rand()%2+2); //left or right
    if(major_direction_ == objectsDirection::LEFT)
    {
        setPos(width-70/2.0f + 1.0f, rand()%static_cast<int>(height-height*0.3f));

    }else{
         setPos(70/2.0f + 1.0f, rand()%static_cast<int>(height-height*0.3f));
    }//if //else
}

void BomberShip::move(){
         switch(movementDirection_)
    {
        case objectsDirection::UP:
            moveup();
            break;
        case objectsDirection::DOWN:
            movedown();
            break;
        default:
            break;
    }//switch
}

void BomberShip::moveup(){

    float maxWidth  = width;
    float minHeight = 70;//height- height*0.25;
    auto newXpos = 0.f;
    auto newYpos = 0.f;
    if(!turningPointAvailable_) slope();

    if(major_direction_ == objectsDirection::LEFT)newXpos = getPos().x-3;
    else newXpos = getPos().x+3;

    newYpos = getPos().y - std::abs(slope_*3);
    if(newXpos < 0 || newXpos > maxWidth){
        setLife(0);
        return;
    }
    if(newYpos >= turningPoint.y && newYpos >= minHeight)
    {
        setPos(newXpos,newYpos);
    }
    else
    {
        turningPointAvailable_ = false;
        movementDirection_ = objectsDirection::DOWN;
        movedown();
    } // if-else
}

void BomberShip::movedown(){
    float maxWidth  = width;
    float maxHeight = height- 70/2.0f;
    auto newXpos = 0.f;
    auto newYpos = 0.f;
    if(!turningPointAvailable_)slope();

    if(major_direction_ ==objectsDirection::LEFT)newXpos = getPos().x-3;
    else newXpos =  getPos().x+3;
     newYpos =  getPos().y+ std::abs(slope_*3);
    if(newXpos < 0 || newXpos > maxWidth){
        setLife(0);
        return;
    }
    if(newYpos <= turningPoint.y && newYpos <= maxHeight){
        setPos(newXpos, newYpos);
    }
    else
    {
        turningPointAvailable_ = false;
        movementDirection_ = objectsDirection::UP;
        moveup();
    }
}

void BomberShip::slope(){
    float minHeight = 70; //height- height*0.25;
    float maxHeight = height- 70/2.0f;

    auto xpos = 0.0f;
    auto ypos = 0.0f;
    auto multFactor = 4;
   // auto Pos_=getPos();

     if(major_direction_ == objectsDirection::LEFT)
     xpos = rand()%static_cast<int>(multFactor*50) + multFactor*50 + getPos().x;// position_.getX_position();
     else  xpos = getPos().x - rand()%static_cast<int>(multFactor*50) + multFactor*50;

      if(movementDirection_ == objectsDirection::DOWN)
    {
        auto y_difference = 0.5f*(maxHeight - getPos().x);
        ypos = rand()%static_cast<int>(y_difference) + getPos().y + y_difference;

       // setPos(xpos, ypos);
       turningPoint.x=xpos;
       turningPoint.y=ypos;

        slope_ = std::abs(getPos().y - ypos)/std::abs(getPos().x - xpos);
        turningPointAvailable_ = true;
    }
    else
    {
        auto y_difference = 0.5f*(getPos().y-minHeight);
        ypos =  getPos().y - rand()%static_cast<int>(y_difference);

        turningPoint.x=xpos;
        turningPoint.y=ypos;
       // setPos(xpos, ypos);

        slope_= std::abs(getPos().y - ypos)/std::abs(getPos().x - xpos);
        turningPointAvailable_ = true;
    }
}

void BomberShip::update()
{
    time_++;
    move();
    updatePos();
    if(time_%200==0){
      major_direction_ = static_cast<objectsDirection>(rand()%2+2);
    }
}
