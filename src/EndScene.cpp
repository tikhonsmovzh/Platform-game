//
// Created by smovzhta on 14.04.2023.
//

#include "EndScene.h"

EndScene::EndScene(int num): Scene(num) {}

void EndScene::Load(int m) {
    backButton = new button({350, 700, 300, 100}, "Back to menu", TextFont);
    resetButton = new button({750, 700, 300, 100}, "Reset", TextFont);

    level = m;
}

void EndScene::update() {
    DrawTextPro(TextFont, "Victory", {screen->x / 2 - 600,300}, {0,0}, 0, 100, 6, BLACK);

    backButton->update();
    resetButton->update();

    if(backButton->isTouch) {
        sceneManager->LoadScene(1, level);
        return;
    }

    if(resetButton->isTouch) {
        if(save->openScenes < level)
            save->openScenes = level;

        sceneManager->LoadScene(2, level);
    }
}

void EndScene::UnLoad() {
    delete backButton;
    delete resetButton;
}