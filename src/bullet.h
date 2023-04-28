//
// Created by smovzhta on 07.04.2023.
//

#ifndef RAYLIBSHOWCASE_BULLET_H
#define RAYLIBSHOWCASE_BULLET_H

#include "Let.h"
#include "chipmunk.hpp"
#include "raylib.h"
#include <iostream>
#include "World.h"
#include "Player.h"

class Player;

class bullet: public Let {
    int rotation;
    unsigned long long startFrame;
    float speed;

    const int lifeTime = 100;

    World* world;

    cp::Vect step;

    Player *player;

public:
    bullet(Vector2, int, float, Player*);

    void Shape(cp::Space*);

    void draw();

    void Touch(Let*, cpContactPointSet);

    void Start(World *);
};


#endif //RAYLIBSHOWCASE_BULLET_H
