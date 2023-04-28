//
// Created by fools on 8/7/2021.
//

#include <iostream>
#include "World.h"

World::World(Camera2D *camera2D, int num): Scene(num) {
    camera = camera2D;

    level = new std::vector<Let*>;
}

void World::update() {
    if(IsKeyPressed(KEY_ESCAPE))
        isPause = !isPause;

    if(!isPause) {
        mSpace->step(1.0 / 60);

        for (int i = 0; i < level->size() - 1; i++) {
            if (level->at(i)->myShape != nullptr) {
                for (int j = i + 1; j < level->size(); j++) {
                    if (level->at(j)->myShape != nullptr) {
                        auto points = cpShapesCollide(*(level->at(j)->myShape), *(level->at(i)->myShape));

                        int saveSize = level->size();

                        if (points.count > 0) {
                            level->at(i)->Touch(level->at(j), points);

                            if (saveSize == level->size())
                                level->at(j)->Touch(level->at(i), points);
                        }
                    }
                }
            }
        }

        frameCount++;
        frameCount %= UINT64_MAX;
    }

    for (int i = 0; i < level->size(); i++)
        level->at(i)->draw();

    for(int i = 0; i < level->size(); i++)
        level->at(i)->drawInterface(camera->target);

    if(isPause)
    {
        DrawRectangleV(camera->target, *screen, {0, 0, 0, 100});

        playButton->update(camera->target);
        mainMenuButton->update(camera->target);
        resetButton->update(camera->target);

        DrawTextPro(TextFont, "Pause", {camera->target.x + 700, camera->target.y + 200},
                    {0,0}, 0, 90, 3, BLACK);

        if(playButton->isTouch)
            isPause = false;

        if(mainMenuButton->isTouch) {
            sceneManager->LoadScene(0, -1);
            return;
        }

        if(resetButton->isTouch) {
            sceneManager->LoadScene(number, numberLevel);
            return;
        }
    }
}

Let* World::FindName(std::string name) {
    for(int i = 0; i < level->size(); i++)
    {
        if(level->at(i)->name == name)
            return level->at(i);
    }
}

Let* World::GetLetShape(std::shared_ptr<cp::Shape> Shape) {
    for(int i = 0; i < level->size(); i++)
    {
        if(level->at(i)->myShape == Shape)
            return level->at(i);
    }

    return nullptr;
}

unsigned long long World::GetFrameCount() { return frameCount;}

void World::Destroy(Let *obj) {
    for (int i = 0; i < level->size(); i++) {
        if(level->at(i) == obj) {
            level->erase(level->begin() + i);

            DeleteObject(obj);

            break;
        }
    }
}

void World::SpawnObject(Let* obj) {
    level->push_back(obj);

    obj->Shape(mSpace);
    obj->Start(this);
}

void World::DeleteObject(Let *obj) {
    if(obj->myBody != nullptr && obj->myBody != mSpace->staticBody)
        mSpace->remove(obj->myBody);

    if(obj->myShape != nullptr)
        mSpace->remove(obj->myShape);

    delete obj;
}

void World::LoadLevel(std::vector<Let *> level1) {
    camera->target = {0, 0};

    for(int i = 0; i < level1.size(); i++)
        level->push_back(level1.at(i));

    for (int i = 0; i < level1.size(); i++) {
        level1.at(i)->Shape(mSpace);
        level1.at(i)->Start(this);
    }
}

void World::Load(int message) {
    camera->target = {0, 0};

    isPause = false;

    mSpace = new cp::Space();
    mSpace->setGravity(cp::Vect(0, -350));

    playButton = new button({screen->x / 2, screen->y / 2, 200, 100}, "Play", TextFont, RED);
    mainMenuButton = new button({screen->x / 2 + 250, screen->y / 2, 200, 100}, "Main menu", TextFont, RED);
    resetButton = new button({screen->x / 2 - 250, screen->y / 2, 200, 100}, "Reset", TextFont, RED);

    numberLevel = message;

    switch (message) {
        case 1: {
            LoadLevel
                    ({
                             new Platform(cp::Vect(-100, 50), cp::Vect(1000, 0)),
                             new Platform(cp::Vect(-150, 350), cp::Vect(-100, 0)),
                             new Platform(cp::Vect(-150, 400), cp::Vect(750, 350)),
                             new Platform(cp::Vect(1000, 800), cp::Vect(1050, 0)),
                             new Platform(cp::Vect(750, 1150), cp::Vect(800, 350)),
                             new Platform(cp::Vect(-100, 1200), cp::Vect(2200, 1150)),
                             new Platform(cp::Vect(1000, 850), cp::Vect(2550, 800)),
                             new Platform(cp::Vect(2500, 1550), cp::Vect(2550, 850)),
                             new Platform(cp::Vect(-100, 1600), cp::Vect(2550, 1550)),
                             new Platform(cp::Vect(-150, 1600), cp::Vect(-100, 1150)),
                             new boxBullet({2000, 1200}),
                             new spawnPoint({1000, 880}),
                             new spawnPoint({1500, 1230}),
                             new turret({1500, 1100}),
                             new turret({900, 1500}),
                             new turret({700, 1500}),
                             new turret({500, 1500}),
                             new chest({2000, 875}),
                             new EndDoor({-50, 1230}),
                             new Player(camera, screen, {100, 100}, save, TextFont)
                     });

            break;
        }

        case  2: {
            LoadLevel
                    ({
                             new Platform(cp::Vect(-100, 50), cp::Vect(3000, 0)),
                             new Platform(cp::Vect(100, 500), cp::Vect(1400, 250)),
                             new EndDoor({150, 530}),
                             new spawnPoint({300, 530}),
                             new spawnPoint({2300, 80}),
                             new chest({750, 525}),
                             new turret({1000, 200}),
                             new turret({500, 200}),
                             new turret({750, 200}),
                             new boxBullet({1350, 650}),
                             new Player(camera, screen, {750, 550}, save, TextFont)
                     });

            for (int i = 0; i < 10; i++)
                SpawnObject(new coin({1250, 650}));

            break;
        }

        case 3: {
            LoadLevel
                    ({
                             new Platform(cp::Vect(-100, 50), cp::Vect(3000, 0)),
                             new EndDoor({150, 80}),
                             new Player(camera, screen, {750, 100}, save, TextFont)
                     });

            break;
        }
    }
}

void World::UnLoad() {
    camera->target = {0, 0};

    while (level->size() != 0) {
        DeleteObject(level->at(0));
        level->erase(level->begin());
    }

    delete mSpace;
    delete playButton;
    delete mainMenuButton;
    delete resetButton;
}

void World::SceneLoad() { sceneManager->LoadScene(3, numberLevel);}