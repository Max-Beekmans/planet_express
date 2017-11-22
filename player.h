//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_PLAYER_H
#define PLANET_EXPRESS_PLAYER_H

#include "Helper/mString.h"

class player {
public:
    explicit player(const char* name = nullptr);
    player(player&& other) noexcept ;
    player&operator=(const player& other) noexcept {
        if(&other != this){
            this->name = other.name;
        }
        return *this;
    }

    mString name;
};


#endif //PLANET_EXPRESS_PLAYER_H
