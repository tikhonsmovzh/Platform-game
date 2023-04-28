//
// Created by smovzhta on 14.04.2023.
//

#ifndef RAYLIBSHOWCASE_ENDSCENE_H
#define RAYLIBSHOWCASE_ENDSCENE_H

#include "Scene.h"
#include "button.h"
#include <iostream>

class EndScene: public Scene{
    button *backButton, *resetButton;

    int level;

public:
    void update();

    EndScene(int);

    void Load(int);

    void UnLoad();
};


#endif //RAYLIBSHOWCASE_ENDSCENE_H
