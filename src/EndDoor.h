//
// Created by tikho on 16.04.2023.
//

#ifndef RAYLIBSHOWCASE_ENDDOOR_H
#define RAYLIBSHOWCASE_ENDDOOR_H

#include "Let.h"
#include "chipmunk.hpp"
#include "raylib.h"
#include <iostream>
#include "World.h"

class EndDoor: public Let  {
    Texture2D doorTexture;

    World *world;

    Let* player;

    const int distance = 150;
public:
    EndDoor(Vector2);

    void draw();

    void Start(World*);
};


#endif //RAYLIBSHOWCASE_ENDDOOR_H
