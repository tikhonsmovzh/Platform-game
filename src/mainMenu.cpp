//
// Created by tikho on 13.04.2023.
//

#include "mainMenu.h"

void mainMenu::update() {
    DrawTextPro(TextFont, "Platform game", {screen->x / 2 - 300,100}, {0,0}, 0, 100, 6, BLACK);

    startButton->update();
    shopButton->update();
    BackButton->update();

    if(startButton->isTouch) {
        sceneManager->LoadScene(1, -1);
        return;
    }

    if(BackButton->isTouch) {
        sceneManager->StopGame();
        return;
    }

    if(shopButton->isTouch) {
        sceneManager->LoadScene(4, -1);
        return;
    }

    DrawTextPro(TextFont, std::to_string(save->countCoin).c_str(), {screen->x * screenCoef + 150, 80}, {0,0,},
                0,40, 3, BLACK);

    DrawCircle(screen->x * screenCoef + 250, 100, 35, GOLD);
    DrawText("$", screen->x * screenCoef + 240, 80, 40, YELLOW);
}

void mainMenu::Load(int) {
    startButton = new button({screen->x / 2, screen->y / 2 - 70, 500, 100}, "Start", TextFont);
    shopButton = new button({screen->x / 2, screen->y / 2 + 70, 500, 100}, "Shop", TextFont);
    BackButton = new button({screen->x / 2, screen->y / 2 + 210, 500, 100}, "Exit", TextFont, RED);
}

void mainMenu::UnLoad() {
    delete startButton;
    delete shopButton;
    delete BackButton;
}

mainMenu::mainMenu(int num): Scene(num) {}