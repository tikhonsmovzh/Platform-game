//
// Created by smovzhta on 03.03.2023.
//

#include "turret.h"
#include <iostream>

turret::turret(Vector2 pos, Color col) : Let(pos, cp::Vect(50, 50), "turret", col) {}

void turret::Shape(cp::Space *mSpace) {
    Space = mSpace;

    myBody = mSpace->staticBody;

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(0, 0),
                                                      cp::Vect(scale.x, 0),
                                                      cp::Vect(scale.x, scale.y),
                                                      cp::Vect(0, scale.y),
                                              });

    myShape->setFriction(10);

    myBody->setPosition(cp::Vect(position.x, position.y));

    mSpace->add(myShape);

    position = physicsToWorldCoord(cpBodyGetPosition(*myBody).x, cpBodyGetPosition(*myBody).y);
}

void turret::draw() {
    DrawRectangle(position.x, position.y - scale.y, scale.x, scale.y, color);

    if(world->isPause) {
        if(isShoot)
            DrawLineEx({(float )(position.x + scale.x / 2), position.y - 10}, {(float)end.x, -(float)end.y}, 10, GOLD);

        DrawMuzzle();

        return;
    }

    if(isWork) {
        Vector2 leg{(float) (position.x + scale.x / 2) -
                    (float) (player->position.x + player->scale.x / 2), position.y - 10 -
                                                                        (float) (player->position.y -
                                                                                 player->scale.y / 2)};

        if (leg.x * leg.x + leg.y * leg.y < distance * distance && player->position.y > position.y - scale.y) {
            double alpha = std::atan2(leg.y, leg.x) * 180 / PI + 90;

            if (alpha >= -maxDegree && alpha <= maxDegree)
                preferredDegree = alpha;

            if (world->GetFrameCount() % 120 > 75) {
                Shooting();
                isShoot = true;
            } else {
                isShoot = false;
            }
        } else {
            if (side)
                preferredDegree = maxDegree + 1;
            else if (!side)
                preferredDegree = -maxDegree - 1;

            if (degree <= -maxDegree)
                side = true;
            else if (degree >= maxDegree)
                side = false;
        }

        double difference = preferredDegree - degree;

        if (difference != 0) {
            if (std::abs(difference) < sensitivity)
                degree = preferredDegree;
            else {
                if (difference > 0)
                    degree += sensitivity;
                else
                    degree -= sensitivity;
            }
        }

        DrawMuzzle();
    }

    if(world->GetFrameCount() % 30 > 15)
        DrawMuzzle();
}

void turret::Start(World *w) {
    player = w->FindName("player");

    world = w;
}

void turret::Shooting() {
    cp::SegmentQueryInfo info;

    start = cp::Vect(position.x + scale.x / 2, -position.y);

    cp::Vect save = degreesToVector(1000 , degree + 180);

    end = cp::Vect(save.x + start.x, save.y - start.y);

    std::shared_ptr<cp::Shape> data = Space->segmentQueryFirst(start,
                                                               end,
                                                               cp::Layers(CP_NO_GROUP), cp::Group(CP_NO_GROUP), &info);

    if(data != nullptr) {
        cp::Vect en = info.hitPoint(start, end);

        end = en;

        DrawLineEx({(float) (position.x + scale.x / 2), position.y - 10},
                   {(float)en.x, (float) -en.y}, 10, GOLD);

        if(world->GetFrameCount() % 30 > 20) {
            Let *shootObject = world->GetLetShape(data);

            if (shootObject->name == "player")
                shootObject->SetDamage(1);
        }
    }
    else
        DrawLineEx({(float )(position.x + scale.x / 2), position.y - 10}, {(float)end.x, -(float)end.y}, 10, GOLD);
}

void turret::SetDamage(int damage) {
    if(health <= 0)
        return;

    health -= damage;

    if(health <= 0)
        isWork = false;
}

void turret::DrawMuzzle() {
    DrawRectanglePro(
            Rectangle{(float) (position.x + scale.x / 2), position.y - 10, transducerScale.x,
                      transducerScale.y},
            {transducerScale.x / 2, 0}, degree, color);
}