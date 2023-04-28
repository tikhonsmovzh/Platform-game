//
// Created by smovzhta on 11.04.2023.
//

#ifndef RAYLIBSHOWCASE_BOXBULLET_H
#define RAYLIBSHOWCASE_BOXBULLET_H

#include "Let.h"
#include "chipmunk.hpp"
#include "raylib.h"
#include <iostream>
#include "World.h"

class boxBullet: public Let{
    World *world;

public:
    boxBullet(Vector2 pos);

    void Shape(cp::Space*);

    void draw();

    void Start(World *);
};


#endif //RAYLIBSHOWCASE_BOXBULLET_H
