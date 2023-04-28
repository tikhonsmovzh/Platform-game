//
// Created by tikho on 14.04.2023.
//

#ifndef RAYLIBSHOWCASE_BUTTON_H
#define RAYLIBSHOWCASE_BUTTON_H

#include <raylib.h>
#include "string"

class button {
    Rectangle rectangle, drawRectangle;

    int scale = 0;

    const int maxScale = 5;

    Color col = RED;

    const int shadowScale = 5;

    Font TextFont;

    Vector2 startPos {0,0};

    Vector2 TextSize;

public:
    button(Rectangle, std::string, Font, Color col = RED);

    void update(Vector2 camera = {0, 0});

    bool isTouch = false;

    std::string text;
};


#endif //RAYLIBSHOWCASE_BUTTON_H
