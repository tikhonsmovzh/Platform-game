//
// Created by tikho on 12.04.2023.
//

#ifndef RAYLIBSHOWCASE_CHEST_H
#define RAYLIBSHOWCASE_CHEST_H

#include "Let.h"
#include "chipmunk.hpp"
#include "raylib.h"
#include <iostream>
#include "World.h"
#include "coin.h"

class chest: public Let {
    bool isOpen = false;

    Texture2D chestTexture, chestOpenTexture;

    Rectangle source;

    float zoom = 80;

    Let* player;

    World *world;

    const int distance = 150;
    const int countCoin = 4;
public:
    chest(Vector2 pos);

    void draw();

    void Start(World*);
};


#endif //RAYLIBSHOWCASE_CHEST_H
