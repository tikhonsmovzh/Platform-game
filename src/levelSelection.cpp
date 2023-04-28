//
// Created by smovzhta on 14.04.2023.
//

#include "levelSelection.h"

levelSelection::levelSelection(int num): Scene(num) {}

void levelSelection::Load(int m) {
    if(m != -1 && save->openScenes < m)
        save->openScenes = m;

    for(int i = 0; i < (int)Size.x; i++)
    {
        for(int j = 0; j < (int)Size.y; j++) {
            int num = i + 1 + j * (int)Size.x;

            std::string txt = std::to_string(num);

            Color col;

            if(save->openScenes + 1 == num)
                col = YELLOW;
            else if(save->openScenes >= num)
                col = GREEN;
            else
                col = RED;

            buttons[i][j] = new button({(float) (i * 100 + screen->x / 2 - 450), (float) (j * 100 + 300), 65, 65}, txt, TextFont, col);
        }
    }

    BackButton = new button({50, 50, 65, 65}, "<", TextFont, RED);
}

void levelSelection::UnLoad() {
    for(int i = 0; i < (int)Size.x; i++)
    {
        for(int j = 0; j < (int)Size.y; j++)
            delete buttons[i][j];
    }

    delete BackButton;
}

void  levelSelection::update() {
    DrawTextPro(TextFont, "Level selection", {screen->x / 2 - 300,100}, {0,0}, 0, 100, 6, BLACK);

    BackButton->update();

    if(BackButton->isTouch) {
        sceneManager->LoadScene(0, -1);
        return;
    }

    for(int i = 0; i < (int)Size.x; i++)
    {
        for(int j = 0; j < (int)Size.y; j++) {
            buttons[i][j]->update();

            int num = i + 1 + j * (int)Size.x;

            if(buttons[i][j]->isTouch && save->openScenes + 1  >= num && num <= CountLevel) {
                sceneManager->LoadScene(2, num);
                return;
            }
        }
    }
}