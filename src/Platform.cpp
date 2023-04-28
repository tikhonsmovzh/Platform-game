//
// Created by smovzhta on 03.02.2023.
//

#include "Platform.h"

void Platform::Shape(cp::Space* mSpace) {
    myBody = mSpace->staticBody;

     myShape = std::make_shared<cp::PolyShape>(myBody,
                                           std::vector<cp::Vect>{
                                                   cp::Vect(Start.x,Start.y),
                                                   cp::Vect(Start.x,End.y),
                                                   cp::Vect(End.x, End.y),
                                                   cp::Vect(End.x,Start.y)
                                           });

    myShape->setFriction(10);

    mSpace->add(myShape);
}

void Platform::draw() {
    DrawTextureTiled(texture, {0, 0, (float)texture.width, (float)texture.height},
                     {position.x, position.y,
                      (float)scale.x, (float)scale.y}, {0, 0}, 0,  sc, color);
}

Platform::Platform(cp::Vect Start, cp::Vect End):
Let({physicsToWorldCoord(Start.x, Start.y)}, cp::Vect((float) (End.x - Start.x), (float) (Start.y - End.y)), "platform", WHITE) {
    this->Start = Start;
    this->End = End;

    static Texture2D textr = LoadTexture("../resources/texture/Platform.png");
    static Texture2D textrDirt = LoadTexture("../resources/texture/PlatformDirt.png");

    if(scale.y < scale.x) {
        sc = (float)scale.y / 250;
        texture = textr;
        return;
    }

    texture = textrDirt;
    sc = (float)scale.x / 250;
}