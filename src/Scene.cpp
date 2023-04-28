//
// Created by tikho on 13.04.2023.
//

#include "Scene.h"

Scene::Scene(int number) {
    this->number = number;
}

void Scene::Start(SceneManager *manager, Font font, Vector2 *screen, Saveer *s) {
    sceneManager = manager;
    TextFont = font;
    this->screen = screen;
    save = s;
}