//
// Created by MaxBe on 11/20/2017.
//

#include "spaceShip.h"

spaceShip::spaceShip(int xpos, int ypos) {
    this->xpos = xpos;
    this->ypos = ypos;
}

spaceShip::spaceShip(spaceShip &other) noexcept {}

spaceShip &spaceShip::operator=(spaceShip &other) noexcept {
    if(&other == this){ return *this; }
    this->xpos = other.xpos;
    this->ypos = other.ypos;
    return *this;
}

spaceShip::spaceShip(spaceShip &&other) noexcept {}

spaceShip& spaceShip::operator=(spaceShip &&other) noexcept {
    if(&other == this){ return *this; }
    this->ypos = other.ypos;
    this->xpos = other.xpos;
    return *this;
}

int spaceShip::move_left() {
    xpos--;
    return xpos;
}

int spaceShip::move_right() {
    xpos++;
    return xpos;
}

int spaceShip::move_up() {
    ypos--;
    return ypos;
}

int spaceShip::move_down() {
    ypos++;
    return ypos;
}



