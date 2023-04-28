//
// Created by fools on 8/7/2021.
//

#ifndef RAYLIBSHOWCASE_WORLD_H
#define RAYLIBSHOWCASE_WORLD_H

#include <raylib.h>
#include <chipmunk.hpp>
#include <vector>
#include <chipmunk_types.h>
#include <string>
#include "Scene.h"
#include "button.h"

#include "Platform.h"
#include "Player.h"
#include "turret.h"
#include "coin.h"
#include "boxBullet.h"
#include "chest.h"
#include "EndDoor.h"
#include "spawnPoint.h"

class World: public Scene {
    Camera2D *camera;

	cp::Space *mSpace;

    button *playButton, *mainMenuButton, *resetButton;

    int numberLevel;

    std::vector<Let*> *level;

    void Move(cpVect velocity);

    unsigned long long frameCount = 0;

    void DeleteObject(Let*);

    void LoadLevel(std::vector<Let*>);

public:
	World(Camera2D*, int);

	void update();

    Let* FindName(std::string);

    Let *GetLetShape(std::shared_ptr<cp::Shape>);

    unsigned long long GetFrameCount();

    void Destroy(Let*);

    void SpawnObject(Let*);

    void Load(int);

    void UnLoad();

    void SceneLoad();

    bool isPause = false;
};

#endif //RAYLIBSHOWCASE_WORLD_H
