//
// Created by MaxBe on 11/20/2017.
//

#include "player.h"

player::player() {
    this->name = mString{"Rodrigo"};
}

player::player(const char * input_name){
    if(input_name != nullptr){
        this->name = mString{input_name};
    } else {
        this->name = mString{"Rodrigo"};
    }
}

player::player(const char *name, spaceShip ship) {
    this->name = mString(name);
    this->ship = ship;
}

player::player(player &&other) noexcept {
    this->name = other.name;
    this->ship = other.ship;
}

player &player::operator=(const player &other) noexcept {
    if(&other != this){ return *this; }
    this->name = {other.name};
    this->ship = {other.ship.xpos , other.ship.ypos};
    return *this;
}

player::player(player &other) noexcept {}

player &player::operator=(player &&other) noexcept {
    this->name = other.name;
    this->ship = other.ship;
    return *this;
}


