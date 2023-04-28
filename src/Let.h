//
// Created by smovzhta on 03.02.2023.
//

#ifndef RAYLIBSHOWCASE_LET_H
#define RAYLIBSHOWCASE_LET_H

#include <chipmunk.hpp>
#include <raylib.h>
#include <string>
#include <map>

class World;

class Let {
protected:
    Color color;

    Vector2 physicsToWorldCoord(float x, float y);

    cp::Vect degreesToVector(double force, int alpha);

public:
    Vector2 position;

    virtual void Shape(cp::Space*){}

    std::string name;

    virtual void draw(){}
    virtual void drawInterface(Vector2){}

    virtual void Touch(Let*, cpContactPointSet){}

    virtual void Start(World *){}

    Let(Vector2 pos, cp::Vect scale, std::string, Color color = RED);

    std::shared_ptr<cp::Shape> myShape;

    std::shared_ptr<cp::Body> myBody;

    cp::Vect scale;

    virtual void SetDamage(int){}
};

#endif //RAYLIBSHOWCASE_LET_H