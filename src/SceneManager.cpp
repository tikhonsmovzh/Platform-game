//
// Created by tikho on 13.04.2023.
//

#include "SceneManager.h"

bool SceneManager::update() {
    isExit = false;

    BeginDrawing();
    BeginMode2D(*camera);

        ClearBackground(WHITE);

        Vector2 scr;

        if(!IsWindowState(FLAG_FULLSCREEN_MODE))
            scr = windowMode;
        else
            scr = fullMode;

        DrawTexturePro(Background, {0,0, (float)Background.width,(float)Background.height},
                   {camera->target.x,camera->target.y, scr.x, scr.y},
                   {0,0}, 0, {255,255,255, 50});

            scenes.at(loadedScene)->update();

    EndMode2D();
    EndDrawing();

    return isExit;
}

void SceneManager::LoadScene(int num, int message) {
    for(int i = 0; i < scenes.size(); i++)
    {
        if(scenes.at(i)->number == num) {
            scenes.at(loadedScene)->UnLoad();

            loadedScene = i;

            scenes.at(i)->Load(message);

            return;
        }
    }
}

SceneManager::SceneManager(Camera2D *camera2D, Vector2 *screen, Saveer *s, std::vector<Scene *> sc) {
    camera = camera2D;
    Font TextFont {};// = LoadFont("../resources/found/technofosiano.ttf");

    if (TextFont.texture.id == 0) TextFont = GetFontDefault();

    for(int i = 0; i < sc.size(); i++) {
        scenes.push_back(sc.at(i));
        sc.at(i)->Start(this, TextFont, screen, s);
    }

    scenes.at(0)->Load(-1);

    loadedScene = 0;

    Background = LoadTexture("../resources/texture/Background.png");
    windowMode = {(float)(Background.width * 3.55),(float)(Background.height * 3.55)};
    fullMode = {(float)(Background.width * 4.13),(float)(Background.height * 4.13)};
}

void SceneManager::reset() {
    scenes.at(loadedScene)->UnLoad();
    scenes.at(loadedScene)->Load(-1);
}

void SceneManager::StopGame() {isExit = true;}