//
// Created by smovzhta on 04.04.2023.
//

#include "coin.h"

coin::coin(Vector2 pos): Let(pos, {25,25}, "coin", GOLD) {}

void coin::draw()
{
    position = physicsToWorldCoord(cpBodyGetPosition(*myBody).x, cpBodyGetPosition(*myBody).y);

    if(position.y > 1000) {
        world->Destroy(this);
        return;
    }

    DrawCircle(position.x, position.y, scale.x, color);

    DrawTextPro(Font(), "$", {position.x, position.y},
                {7.5,15}, -cpBodyGetAngle(*myBody) / 2 / PI * 360,
                30, 0, YELLOW);

    cp::Vect velocity = myBody->getVelocity();

    myBody->setVelocity(cp::Vect(velocity.x * 0.99, velocity.y));
}

void coin::Shape(cp::Space * mSpace) {
    myBody = std::make_shared<cp::Body>(1, cp::momentForCircle(1, 0, scale.x));

    myShape = std::make_shared<cp::CircleShape>(myBody, scale.x);

    myShape->setFriction(10);
    myShape->setElasticity(0.5);

    myBody->setPosition(cp::Vect(position.x, position.y));
    myBody->setVelocity(cpvzero);

    mSpace->add(myShape);
    mSpace->add(myBody);
}

void coin::Start(World *w) {world = w;}