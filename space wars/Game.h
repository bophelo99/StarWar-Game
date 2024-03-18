#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include "Asteroid.h"
#include <list>
#include <vector>
#include "Ship.h"
#include "Bullet.h"
#include "EnemyShip.h"
#include <string>
#include <thread>
#include "SelectableText.h"
#include "shield.h"
#include "time.h"
#include "BomberShip.h"
#include "mines.h"
#include "UpgradeBulletLaser.h"
#include "mountain.h"
#include "Landtrees.h"
#include "cloud.h"
#include "humanoid.h"
#include "AbductingLanders.h"

class Game {
    const int vol=3;
    int asteroidNumber;
    int enemiesNumber;
    int ShieldNumber;
    int BombersNumber;
    int humanoidNumber;
    int score;
    int bulletCoolDown;
    int width,height;
    int numberOfCosos;
    unsigned long int time;
    float frameTime;
    sf::Font font;
    std::string language, highScoreString, NumberOFshieldString;
    std::thread t1;
    sf::Text fpsText, shieldText;
    std::string fpsString;
    bool updateFps;

    sf::RenderWindow &window1;
    sf::RectangleShape background;
    sf::Event event;

    sf::Clock clock;
    sf::Time currentTime;
    float getFrameTime();
    bool gameOver;


    sf::Sound explosionSound;
    sf::Sound explosionSound2;
    sf::Sound shotSound1;
    sf::Sound shotSound2;

    sf::Text scoreText;

    sf::Texture asteroidTexture;
    Animation asteroidAnim;
    sf::Texture bulletTexture;
    Animation bulletAnim;
    sf::Texture enemyBulletTexture;
    Animation enemyBulletAnim;

    sf::Texture cosoMisteriosoTexture;
    Animation cosoMisteriosoAnim;

    sf::Texture SheildTexture;
    Animation ShieldAnim;

    SelectableText resumeButton;
    SelectableText exitButton;

    std::list<Entity*> entities;
    ///std::list<EnemyShip*> enemies;

    Ship *ship;
    EnemyShip *enemyShip;

    ///parameters to sets Landscape scrollings screens
    mountain *mountain_, *mountain_2;
    Landtrees *trees_, *trees_2;
    cloud *cloud_, *cloud_2;



    sf::Texture humanoidTexture, MountainTexture, treeTexture, cloudTexture, mineTexture, BombersTexture, shipTexture, shipTexture_M, shieldHeads, enemyShipTexture, enemyShipTexture_M, explosionTextureA,explosionTextureB,explosionTextureC;
    Animation HumanoidANim, MountainAnim,treeAnim, cloudAnim, mineAnim, BombersAnim, shipAnim, shipAnimBack, shipAnim_M, shieldHeadsAnim, shipAnim_MB, enemyShipAnim, enemyShipAnim_M, explosionAnimA, explosionAnimB,explosionAnimC ;

    void checkColition(Entity* a);
    void gameLoop();
    void eventListener();
    void drawWindow();
    bool isCollide(Entity *a,Entity *b);
    int readHighestScore();
    void gameOverScreen();
    void saveScore(int);
    void pauseMenu();
    sf::Vector2i randomGenerator();

public:
    Game(short int width,short int height,std::string _language,sf::RenderWindow &_window1);

private:
    timer shieldtimer_;
    double shieldReleaseTime, shieldLastReleaseTime;

    timer Asteroidtimer_;
    double AsteroidReleaseTime, AsteroidLastReleaseTime;

    timer Bomberstimer_;
    double BombersReleaseTime, BombersLastReleaseTime;

    timer minetimer_;
    double mineReleaseTime, mineLastReleaseTime;

    timer humanoidtimer_;
    double humanoidReleaseTime, humanoidLastReleaseTime;

};
