//
// Created by smovzhta on 28.02.2023.
//

#include "Player.h"

void Player::draw() {
    if(position.y > 1000 || health <= 1) {
        myBody->setPosition(savePosition);

        health = startHealth;
        bulletCount = startBullet;
    }

    position = physicsToWorldCoord(cpBodyGetPosition(*myBody).x, cpBodyGetPosition(*myBody).y);

    auto velocity = cpvzero;

    if(IsKeyDown(KEY_LEFT_CONTROL)) {
        if (IsKeyDown(KEY_A))
            velocity.x = 600;
        else if (IsKeyDown(KEY_D))
            velocity.x = -600;
    }
    else {
        if (IsKeyDown(KEY_A))
            velocity.x = 250;
        else if (IsKeyDown(KEY_D))
            velocity.x = -250;
    }

    Move(velocity);

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && world->GetFrameCount() - shootTime > ShootDelay && bulletCount > 0 && !world->isPause) {
        Vector2 pos {(float )(camera->target.x + screen->x / 2 + scale.x), -(float )(camera->target.y + screen->y / 2 + 25)};

        int degree = (int)(270 -std::atan2( -(screen->y / 2 - GetMouseY()), (screen->x / 2 + scale.x) - GetMouseX()) * 180 / PI);

        cp::Vect startPos = degreesToVector(1.2, degree);

        world->SpawnObject(new bullet(Vector2{pos.x + (float)startPos.x, pos.y + (float )startPos.y}, degree, 10, this));

        bulletCount--;

        shootTime = world->GetFrameCount();
    }

    DrawRectangle(position.x, position.y - scale.y, scale.x, scale.y, color);

    if(camera != nullptr)
        camera->target = (Vector2) {(float)(position.x - scale.x / 2 - screen->x / 2),
                               (float)(position.y - scale.y - screen->y / 2)};

    isTouch = false;
}

void Player::drawInterface(Vector2 camPos) {
    DrawRectangle(position.x - (scaleHealth - scale.x) / 2 - width, position.y - scale.y - (20 + width),
                  scaleHealth + 2 * width, 10 + width * 2,Color {130, 130, 130, 150});

    DrawRectangle(position.x - (scaleHealth - scale.x) / 2, position.y - scale.y - 20,
                  scaleHealth * ((float)health / 100),10,GREEN);

    DrawTextPro(TextFont, std::to_string(save->countCoin).c_str(), {camPos.x + screen->x * screenCoef + 150, camPos.y + 80}, {0,0,},
                0,40, 3, BLACK);
    DrawCircle(camPos.x + screen->x * screenCoef + 250, camPos.y + 100, 35, GOLD);
    DrawText("$", camPos.x + screen->x * screenCoef + 240, camPos.y + 80, 40, YELLOW);

    DrawTextPro(TextFont, std::to_string(bulletCount).c_str(), {camPos.x + screen->x * screenCoef, camPos.y + 80}, {0,0,},
                0,40, 3, BLACK);
    DrawRectangle(camPos.x + screen->x * screenCoef + 50, camPos.y + 86, 14, 28, GRAY);
}

void Player::Shape(cp::Space *mSpace) {
    myBody = std::make_shared<cp::Body>(4, INFINITY);

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                             std::vector<cp::Vect>{
                                                     cp::Vect(0, 0),
                                                     cp::Vect(scale.x, 0),
                                                     cp::Vect(scale.x, scale.y),
                                                     cp::Vect(0, scale.y),
                                             });

    myShape->setFriction(10);

    myBody->setPosition(savePosition);

    myBody->setVelocity(cpvzero);

    mSpace->add(myShape);
    mSpace->add(myBody);
}

Player::Player(Camera2D *camera2D, Vector2 *screen, Vector2 pos, Saveer *s, Font TextFont, Color col): Let(pos, cp::Vect(50, 100), "player", col) {
    camera = camera2D;
    this->screen = screen;

    savePosition.x = position.x;
    savePosition.y = position.y;

    health = startHealth;
    bulletCount = startBullet;
    this->TextFont = TextFont;

    save = s;
}

void Player::Move(cpVect velocity)
{
    if (points.count > 0 && isTouch) {
        if (((int)(points.normal.x) == 1 && velocity.x > 0) || ((int)(points.normal.x) == -1 && velocity.x < 0)) {
            if(touchObject->name == "platform" && IsKeyDown(KEY_LEFT_CONTROL) &&
                    (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)))
                cpBodySetVelocity(*myBody, {-velocity.x / 6, 350});
            else
                cpBodySetVelocity(*myBody, {-velocity.x, myBody->getVelocity().y});
        }
        else
            cpShapeSetSurfaceVelocity(*myShape, velocity);
    }
    else
        cpBodySetVelocity(*myBody, {-velocity.x, myBody->getVelocity().y});
}

void Player::Touch(Let *object, cpContactPointSet points) {
    this->points = points;
    isTouch = true;
    touchObject = object;

    if ((int)(points.normal.x) == 0 && (int)(points.normal.y) == -1 && (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)))
        cpBodyApplyImpulseAtLocalPoint(*myBody, {0, 1500}, {});

    if(object->name == "coin") {
        save->countCoin++;

        world->Destroy(object);
    } else if(object->name == "boxBullet") {
        SetBulletCount(20);
        health = 100;
        world->Destroy(object);
    }
}

void Player::SetDamage(int damage) { health -= damage; }

void Player::Start(World *w) {world = w;}

void Player::SetBulletCount(int count) {
    bulletCount += count;

    if(bulletCount > maxBullet)
        bulletCount = maxBullet;
}