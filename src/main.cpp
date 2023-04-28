#include <raylib.h>
#include "World.h"
#include "SceneManager.h"
#include "mainMenu.h"
#include "levelSelection.h"
#include "EndScene.h"
#include "Saveer.h"
#include "shopMenu.h"

int main() {
    Vector2 screen {1596, 950};

    Camera2D camera {{0, 0}, {0, 0}, 0, 1};

    Saveer s;

    InitWindow(screen.x, screen.y, "Platform game");
    SetTargetFPS(60);
    SetExitKey(KEY_TAB);

//    screen = {(float)GetMonitorWidth(0), (float)GetMonitorHeight(0)};
//    SetWindowSize(screen.x, screen.y);
//    SetWindowState(FLAG_FULLSCREEN_MODE);

    SceneManager scene (&camera, &screen, &s, {
            new mainMenu(0),
            new levelSelection(1),
            new World(&camera, 2),
            new EndScene(3),
            new shopMenu(4)
    });

	while (!WindowShouldClose() && !scene.update());

	CloseWindow();

	return 0;
}