//
// Created by tikho on 18.04.2023.
//

#ifndef RAYLIBSHOWCASE_SAVEER_H
#define RAYLIBSHOWCASE_SAVEER_H

#include <fstream>

class Saveer {
    std::fstream file;

public:
    int countCoin;

    int openScenes;

    Saveer();
    ~Saveer();
};


#endif //RAYLIBSHOWCASE_SAVEER_H
