//
// Created by tikho on 13.04.2023.
//

#ifndef RAYLIBSHOWCASE_MAINMENU_H
#define RAYLIBSHOWCASE_MAINMENU_H

#include "Scene.h"
#include <raylib.h>
#include "button.h"

class mainMenu: public Scene {
    button *startButton, *BackButton, *shopButton;

    const float screenCoef = 0.8;

public:
    void update();

    mainMenu(int);

    void Load(int);

    void UnLoad();
};


#endif //RAYLIBSHOWCASE_MAINMENU_H
