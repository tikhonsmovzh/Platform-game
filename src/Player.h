//
// Created by smovzhta on 28.02.2023.
//

#ifndef RAYLIBSHOWCASE_PLAYER_H
#define RAYLIBSHOWCASE_PLAYER_H

#include "Let.h"
#include <chipmunk.hpp>
#include <raylib.h>
#include <iostream>
#include "World.h"
#include "bullet.h"
#include "Saveer.h"

class Player: public Let{
    void Move(cpVect velocity);

    const int scaleHealth = 75;

    const int width = 4;

    const int startHealth = 100;
    const int startBullet = 10;

    const int maxBullet = 50;

    const int ShootDelay = 42;

    const float screenCoef = 0.8;

    Camera2D *camera;

    Vector2 *screen;

    cpContactPointSet points;

    unsigned long long shootTime = 0;

    bool isTouch = false;

    int health, bulletCount;

    World* world;

    Let *touchObject;

    Font TextFont;

    Saveer *save;

public:
    Player(Camera2D *, Vector2 *, Vector2, Saveer *, Font , Color col = BLUE);

    void Shape(cp::Space*);

    void draw();

    void drawInterface(Vector2);

    void Touch(Let*, cpContactPointSet);

    void SetDamage(int);

    void Start(World *);

    void SetBulletCount(int count);

    cp::Vect savePosition;
};


#endif //RAYLIBSHOWCASE_PLAYER_H