//
// Created by smovzhta on 04.04.2023.
//

#ifndef RAYLIBSHOWCASE_COIN_H
#define RAYLIBSHOWCASE_COIN_H

#include "Let.h"
#include "World.h"

class coin: public Let {
    World *world;

public:
    coin(Vector2);

    void Shape(cp::Space*);

    void draw();

    void Start(World *);
};


#endif //RAYLIBSHOWCASE_COIN_H
