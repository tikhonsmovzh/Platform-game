//
// Created by tikho on 17.04.2023.
//

#ifndef RAYLIBSHOWCASE_SPAWNPOINT_H
#define RAYLIBSHOWCASE_SPAWNPOINT_H

#include "Let.h"
#include "chipmunk.hpp"
#include "raylib.h"
#include <iostream>
#include "World.h"
#include "Player.h"

class Player;

class spawnPoint: public Let {
    Texture2D spawnPointTexture, spawnPointActiveTexture;

    World *world;

    Player * player;

    const int distance = 150;

    Rectangle source, dest;

    bool isActive = false;

public:
    spawnPoint(Vector2);

    void draw();

    void Start(World*);
};


#endif //RAYLIBSHOWCASE_SPAWNPOINT_H
