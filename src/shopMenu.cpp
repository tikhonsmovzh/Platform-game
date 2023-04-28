//
// Created by smovzhta on 25.04.2023.
//

#include "shopMenu.h"

shopMenu::shopMenu(int num): Scene(num) {}

void shopMenu::update() {
    BackButton->update();
    PreviousButton->update();
    NextButton->update();

    DrawRectangle((int)(screen->x / 2.0 - scale.x / 2.0), (int)(screen->y / 2.0 - scale.y / 2.0), scale.x, scale.y, cols[seeNum].col);

    if(cols[seeNum].isBuy) {
        ChoiceButton->update();

        if(seeNum == chooseNum)
            ChoiceButton->text = "selected";
        else {
            if(ChoiceButton->isTouch)
                chooseNum = seeNum;

            ChoiceButton->text = "choose";
        }
    }
    else {
        BuyButton->update();

        if(BuyButton->isTouch) {
            cols[seeNum].isBuy = true;
            chooseNum = seeNum;
            return;
        }
    }

    if(BackButton->isTouch) {
        sceneManager->LoadScene(0, -1);
        return;
    }

    if(PreviousButton->isTouch) {
        seeNum--;
        if(seeNum < 0)
            seeNum = count - 1;
        return;
    }

    if(NextButton->isTouch) {
        seeNum++;
        if(seeNum >= count)
            seeNum = 0;
        return;
    }
}

void shopMenu::Load(int) {
    BackButton = new button({50, 50, 65, 65}, "<", TextFont, RED);
    ChoiceButton = new button({screen->x / 2, screen->y / 2 + 300, 200, 100}, "choose", TextFont, RED);
    BuyButton = new button({screen->x / 2, screen->y / 2 + 300, 200, 100}, "buy", TextFont, RED);
    PreviousButton = new button({screen->x / 2 - 200, screen->y / 2, 65, 65}, "<", TextFont, RED);
    NextButton = new button({screen->x / 2 + 200, screen->y / 2, 65, 65}, ">", TextFont, RED);
}

void shopMenu::UnLoad() {
    delete BackButton;
    delete ChoiceButton;
    delete BuyButton;
    delete PreviousButton;
    delete NextButton;
}