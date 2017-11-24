//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_PLAYER_H
#define PLANET_EXPRESS_PLAYER_H

#include "Helper/mString.h"
#include "spaceShip.h"

class player {
public:
    explicit player(const char* name = nullptr);
    player(const char* name, spaceShip ship);
    player(player&& other) noexcept ;
    player(player& other) noexcept ;
    player&operator=(const player& other) noexcept ;
    player&operator=(player&& other) noexcept ;

    mString name;
    spaceShip ship;
};


#endif //PLANET_EXPRESS_PLAYER_H
