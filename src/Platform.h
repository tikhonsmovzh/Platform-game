//
// Created by smovzhta on 03.02.2023.
//

#ifndef RAYLIBSHOWCASE_PLATFORM_H
#define RAYLIBSHOWCASE_PLATFORM_H

#include "Let.h"
#include <chipmunk.hpp>
#include <raylib.h>
#include <string>
#include "World.h"
#include <map>

class Platform: public Let {
    cp::Vect Start, End;

    Texture2D texture;

    float sc;

public:
    Platform(cp::Vect Start, cp::Vect EndD);

    void Shape(cp::Space*);

    void draw();
};


#endif //RAYLIBSHOWCASE_PLATFORM_H