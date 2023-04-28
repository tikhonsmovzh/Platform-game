//
// Created by tikho on 14.04.2023.
//

#include "button.h"

button::button(Rectangle rect, std::string text, Font TextFont, Color col) {
    rectangle = rect;

    startPos = {rectangle.x, rectangle.y};

    rectangle.x -= rectangle.width / 2;
    rectangle.y -= rectangle.height / 2;

    drawRectangle = rectangle;

    this->text = text;
    this->TextFont = TextFont;

    this->col = col;
}

void button::update(Vector2 camera) {
    Color drawCol = col;
    isTouch = false;

    if (!CheckCollisionPointRec({(float)GetMouseX() + camera.x, (float)GetMouseY() + camera.y}, drawRectangle)) {
        if(scale > 0)
            scale--;
    } else{
        if(scale < maxScale)
            scale++;

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            drawCol = { (unsigned char)(col.r - 30), col.g, col.b, col.a } ;

        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            isTouch = true;
    }

    drawRectangle = {rectangle.x - scale + camera.x, rectangle.y - scale + camera.y, rectangle.width + scale * 2, rectangle.height + scale * 2};

        DrawRectanglePro({drawRectangle.x - shadowScale, drawRectangle.y - shadowScale,
                          drawRectangle.width + shadowScale * 2, drawRectangle.height + shadowScale * 2},
                         {0,0}, 0, {0,0,0, (unsigned char)(100 * ((float)scale / maxScale))});

    DrawRectanglePro(drawRectangle, {0, 0}, 0, drawCol);

    TextSize = {(float)((text.size()) * 20) , 40};

    DrawTextPro(TextFont, text.c_str(), {startPos.x + camera.x, startPos.y + camera.y}, {TextSize.x / 2, TextSize.y / 2},0, 40, 3, BLACK);
}