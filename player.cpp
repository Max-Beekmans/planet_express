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
}

player::player(player &&other) {
    this->ship = other.ship;
    this->name = other.name;
}
