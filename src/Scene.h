//
// Created by tikho on 13.04.2023.
//

#ifndef RAYLIBSHOWCASE_SCENE_H
#define RAYLIBSHOWCASE_SCENE_H

#include "SceneManager.h"
#include <raylib.h>
#include "Saveer.h"

class SceneManager;

class Scene {
protected:
    SceneManager *sceneManager;

    Font TextFont;

    Vector2 *screen;

    Saveer *save;

public:
    int number;

    Scene(int);

    virtual void update(){}

    virtual void Load(int){}

    virtual void UnLoad(){}

    void Start(SceneManager *, Font, Vector2 *, Saveer *);
};


#endif //RAYLIBSHOWCASE_SCENE_H
