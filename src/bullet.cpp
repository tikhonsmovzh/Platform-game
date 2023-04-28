//
// Created by smovzhta on 07.04.2023.
//

#include "bullet.h"

bullet::bullet(Vector2 pos, int rot, float speed, Player *pl) : Let(pos, {10, 20}, "bullet", GRAY) {
    rotation = rot;
    this->speed = speed;
    step = degreesToVector(speed, rotation);
    player = pl;
}

void bullet::Shape(cp::Space *mSpace) {
    myBody = std::make_shared<cp::Body>(1, 1);

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(0, 0),
                                                      cp::Vect(scale.x, 0),
                                                      cp::Vect(scale.x, scale.y),
                                                      cp::Vect(0, scale.y),
                                              });

    myShape->setFriction(10);

    myBody->setPosition(cp::Vect(position.x, position.y));

    cpBodySetAngle(*myBody, -rotation / 360 * PI * 2);

    mSpace->add(myBody);
    mSpace->add(myShape);

    position = physicsToWorldCoord(cpBodyGetPosition(*myBody).x, cpBodyGetPosition(*myBody).y + scale.y);
}

void bullet::draw() {
    position = physicsToWorldCoord(cpBodyGetPosition(*myBody).x, cpBodyGetPosition(*myBody).y + scale.y);

    cpBodySetVelocity(*myBody, step);

    DrawRectanglePro({position.x, position.y, (float) scale.x, (float) scale.y},
                     {0, (float) scale.y}, rotation, color);

    if (world->GetFrameCount() - startFrame > lifeTime)
        world->Destroy(this);
}

void bullet::Touch(Let *object, cpContactPointSet) {
    if (object->name == "turret")
        object->SetDamage(1);

    if(object->name == "boxBullet" && player != nullptr) {
        player->SetBulletCount(10);
        world->Destroy(object);
    }

    if (object->name != "player" || object->name != "bullet")
        world->Destroy(this);
}

void bullet::Start(World *w) {
    world = w;
    startFrame = world->GetFrameCount();
}