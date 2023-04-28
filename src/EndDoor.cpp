//
// Created by tikho on 16.04.2023.
//

#include "EndDoor.h"

EndDoor::EndDoor(Vector2 pos):  Let(pos, {15,30}, "chest", WHITE) {
    static Texture2D texture2D = LoadTexture("../resources/texture/door.png");

    doorTexture = texture2D;

    position = physicsToWorldCoord(position.x, position.y + 130);
}

void EndDoor::Start(World *w) {
    world = w;
    player = w->FindName("player");
}

void EndDoor::draw() {
    Vector2 leg{(float) (position.x + scale.x / 2) -
                (float) (player->position.x + player->scale.x / 2), (float)(position.y + scale.y / 2) -
                                                                    (float) (player->position.y -
                                                                             player->scale.y / 2)};

    if(leg.x * leg.x + leg.y * leg.y < distance * distance && IsKeyPressed(KEY_E)) {
        world->SceneLoad();

        return;
    }

    DrawTexturePro(doorTexture, {0, 0, (float)doorTexture.width, (float)doorTexture.height},
                   {position.x, position.y, (float)(doorTexture.width / 2.8), (float)(doorTexture.height / 2.8)},
                   {0,0}, 0, color);
}