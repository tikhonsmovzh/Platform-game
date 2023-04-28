//
// Created by tikho on 13.04.2023.
//

#ifndef RAYLIBSHOWCASE_SCENEMANAGER_H
#define RAYLIBSHOWCASE_SCENEMANAGER_H

#include "Scene.h"
#include "vector"
#include <raylib.h>
#include <iostream>
#include "Saveer.h"

class Scene;

class SceneManager {
    std::vector<Scene *> scenes;

    int loadedScene = 0;

    Camera2D *camera;

    Texture2D Background;

    Vector2 fullMode, windowMode;

    bool isExit = false;

public:
    bool update();

    void LoadScene(int, int);

    void reset();

    SceneManager(Camera2D *, Vector2 *, Saveer *, std::vector<Scene*>);

    void StopGame();
};


#endif //RAYLIBSHOWCASE_SCENEMANAGER_H
