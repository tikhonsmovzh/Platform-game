//
// Created by smovzhta on 14.04.2023.
//

#ifndef RAYLIBSHOWCASE_LEVELSELECTION_H
#define RAYLIBSHOWCASE_LEVELSELECTION_H

#include "Scene.h"
#include <raylib.h>
#include "button.h"

class levelSelection: public Scene {
    const Vector2 Size {10,5};

    button *(buttons[10][5]), *BackButton;

    const int CountLevel = 3;

public:
    void update();

    levelSelection(int);

    void Load(int);

    void UnLoad();
};


#endif //RAYLIBSHOWCASE_LEVELSELECTION_H
