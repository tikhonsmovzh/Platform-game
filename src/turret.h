//
// Created by smovzhta on 03.03.2023.
//

#ifndef RAYLIBSHOWCASE_TURRET_H
#define RAYLIBSHOWCASE_TURRET_H

#include "Let.h"
#include <chipmunk.hpp>
#include <raylib.h>
#include <string>
#include "World.h"
#include "Player.h"

class turret : public Let {
    const Vector2 transducerScale{20, 50};

    Let* player;

    int health = 7;

    double preferredDegree = -64,  degree = 0;

    bool side = true, isWork = true, isShoot = false;

    const int maxDegree = 80;

    const double sensitivity = 0.55;

    const int distance = 650;

    cp::Space *Space;

    void Shooting();

    World *world;

    void DrawMuzzle();

    cp::Vect start, end;

public:
    turret(Vector2, Color col = ORANGE);

    void Shape(cp::Space*);

    void draw();

    void Start(World*);

    void SetDamage(int);
};


#endif //RAYLIBSHOWCASE_TURRET_H
