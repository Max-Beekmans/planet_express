//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_PLAYER_H
#define PLANET_EXPRESS_PLAYER_H

#include "ship.h"
#include "Helper/mString.h"

class player {
public:
    player(const char* name = nullptr);
    player(player&& other);
    player&operator=(const player& other){
        if(&other != this){
            ship = {other.ship};
        }
        return *this;
    }
    ship ship;
    mString name;
};


#endif //PLANET_EXPRESS_PLAYER_H
