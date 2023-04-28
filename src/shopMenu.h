//
// Created by smovzhta on 25.04.2023.
//

#ifndef RAYLIBSHOWCASE_SHOPMENU_H
#define RAYLIBSHOWCASE_SHOPMENU_H

#include "Scene.h"
#include <raylib.h>
#include "button.h"

typedef struct skin
{
    Color col;
    int price;
    bool isBuy = false;
};

class shopMenu: public Scene {
    button *BackButton, *BuyButton, *ChoiceButton, *NextButton, *PreviousButton;

    const int count = 3;

    int chooseNum = 0;
    int seeNum = 0;

    const Vector2 scale {100, 200};

    skin cols[3]{{RED, 5}, {BLUE, 5}, {GREEN, 5}};

public:
    void update();

    shopMenu(int);

    void Load(int);

    void UnLoad();
};


#endif //RAYLIBSHOWCASE_SHOPMENU_H
