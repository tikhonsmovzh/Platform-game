//
// Created by smovzhta on 03.02.2023.
//

#include "Let.h"

Let::Let(Vector2 pos, cp::Vect scale, std::string name, Color color) {
    position = pos;
    this->color = color;
    this->scale = scale;
    this->name = name;
}

Vector2 Let::physicsToWorldCoord(float x, float y) {
    return {x, -y};
}

cp::Vect Let::degreesToVector(double force, int alpha)
{
    double yC = alpha * PI / 180;

    return cp::Vect((float)(force * std::sin(yC) * 180 / PI), (float)(force * std::cos(yC) * 180 / PI));
}