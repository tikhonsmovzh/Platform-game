//
// Created by tikho on 18.04.2023.
//

#include "Saveer.h"

Saveer::Saveer() {
    file.open("../resources/data.txt", std::ios::in);

    file >> countCoin;
    file >> openScenes;
}

Saveer::~Saveer() {
    file.close();
    file.open("../resources/data.txt", std::ios::out);

    file << countCoin << ' ' << openScenes;
    file.close();
}