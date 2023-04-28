//
// Created by tikho on 17.04.2023.
//

#include "spawnPoint.h"

spawnPoint::spawnPoint(Vector2 pos):  Let(pos, {15,30}, "chest", WHITE) {
    static Texture2D Active = LoadTexture("../resources/texture/spawnPointActive.png");
    static Texture2D Texturer = LoadTexture("../resources/texture/spawnPoint.png");

    spawnPointTexture = Texturer;
    spawnPointActiveTexture = Active;

    position = physicsToWorldCoord(position.x, position.y + 100);
    source = {0, 0, (float)spawnPointTexture.width, (float)spawnPointTexture.height};
    dest = {position.x, position.y, (float)(spawnPointTexture.width / 3.9), (float)(spawnPointTexture.height / 3.9)};
}

void spawnPoint::Start(World *w) {
    world = w;
    player = (Player *)(w->FindName("player"));
}

void spawnPoint::draw() {
    Vector2 leg{(float) (position.x + scale.x / 2) -
                (float) (player->position.x + player->scale.x / 2), (float)(position.y + scale.y / 2) -
                                                                    (float) (player->position.y -
                                                                             player->scale.y / 2)};

    if(leg.x * leg.x + leg.y * leg.y < distance * distance && IsKeyPressed(KEY_E) && !isActive) {
        isActive = !isActive;

        player->savePosition = cp::Vect(position.x + player->scale.x / 2, -position.y - 100);
    }

    if(isActive)
        DrawTexturePro(spawnPointActiveTexture, source, dest, {0,0}, 0, color);
    else
        DrawTexturePro(spawnPointTexture, source, dest, {0,0}, 0, color);
}