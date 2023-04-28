//
// Created by smovzhta on 11.04.2023.
//

#include "boxBullet.h"

boxBullet::boxBullet(Vector2 pos): Let(pos, cp::Vect(50,50),"boxBullet", LIGHTGRAY) {}

void boxBullet::Shape(cp::Space *mSpace) {
    myBody = std::make_shared<cp::Body>(4, 500);

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(-scale.x / 2, -scale.y / 2),
                                                      cp::Vect(scale.x / 2, -scale.y / 2),
                                                      cp::Vect(scale.x / 2, scale.y / 2),
                                                      cp::Vect(-scale.x / 2, scale.y / 2),
                                              });

    myShape->setFriction(1);

    myBody->setPosition(cp::Vect(position.x, position.y));

    mSpace->add(myBody);
    mSpace->add(myShape);
}

void boxBullet::draw() {
    position = physicsToWorldCoord(cpBodyGetPosition(*myBody).x, cpBodyGetPosition(*myBody).y);

    if(position.y > 1000) {
        world->Destroy(this);
        return;
    }

    int rotation = -cpBodyGetAngle(*myBody) / 2 / PI * 360;

    DrawRectanglePro({position.x, position.y, (float)scale.x, (float)scale.y},
                     {(float)scale.x / 2, (float)scale.y / 2}, rotation, color);

    DrawRectanglePro({position.x, position.y, 10, 20},
                     {5, 10}, rotation, GRAY);
}

void boxBullet::Start(World *w) {world = w;}