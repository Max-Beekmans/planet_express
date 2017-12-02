//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_PLAYER_H
#define PLANET_EXPRESS_PLAYER_H

#include "../Helper/MyString.h"
#include "SpaceShip.h"

class Player {
public:
    Player();
    explicit Player(const char* name);
    Player(const char* name, SpaceShip& ship);
    Player(Player&& other) noexcept ;
    Player(Player& other) noexcept ;
    Player&operator=(const Player& other) noexcept ;
    Player&operator=(Player&& other) noexcept ;

    MyString name;
    SpaceShip ship;
    int victory_point = 0;
};


#endif //PLANET_EXPRESS_PLAYER_H
