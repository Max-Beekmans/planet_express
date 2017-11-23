//
// Created by MaxBe on 11/20/2017.
//

#include "player.h"

player::player(const char *name) {
    if(name != nullptr){
        this->name = mString{name};
    } else {
        this->name = mString{"Rodrigo"};
    }

    this->ship = ship;
}

player::player(player &&other) noexcept {
    this->name = other.name;
    this->ship = other.ship;
}

player &player::operator=(const player &other) {
    if(&other != this){
        this->name = other.name;
        this->ship = other.ship;
    }
    return *this;
}
