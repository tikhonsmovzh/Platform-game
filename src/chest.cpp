//
// Created by tikho on 12.04.2023.
//

#include "chest.h"

chest::chest(Vector2 pos): Let(pos, {30,25}, "chest", WHITE) {
    static Texture2D ch = LoadTexture("../resources/texture/chest.png");
    static Texture2D cho = LoadTexture("../resources/texture/chest_open.png");

    chestTexture = ch;
    chestOpenTexture = cho;

    source = {0, 0, (float)chestTexture.width, (float)chestTexture.height};

    scale.x = (float)(chestTexture.width / zoom * scale.x);
    scale.y = (float)(chestTexture.height / zoom * scale.y);

    position = physicsToWorldCoord(position.x, position.y + 115);
}

void chest::draw() {
    Vector2 leg{(float) (position.x + scale.x / 2) -
                (float) (player->position.x + player->scale.x / 2), (float)(position.y + scale.y / 2) -
                                                                    (float) (player->position.y -
                                                                             player->scale.y / 2)};

    if(leg.x * leg.x + leg.y * leg.y < distance * distance && !isOpen && IsKeyPressed(KEY_E)) {
        isOpen = true;

        for(int i = 0; i < countCoin; i++)
            world->SpawnObject(new coin({ (float)(position.x + scale.x / 2), -position.y}));
    }

    if (isOpen) {
        DrawTexturePro(chestOpenTexture, source,
                       {position.x, position.y, (float)scale.x, (float)scale.y},
                       {0, 0}, 0, color);
    } else {
        DrawTexturePro(chestTexture, source,
                       {position.x, position.y, (float)scale.x, (float)scale.y},
                       {0, 0}, 0, color);
    }
}

void chest::Start(World *w) {
    player = w->FindName("player");
    world = w;
}