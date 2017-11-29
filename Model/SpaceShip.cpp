//
// Created by MaxBe on 11/20/2017.
//

#include "SpaceShip.h"

SpaceShip::SpaceShip(int xpos, int ypos) {
    this->xpos = xpos;
    this->ypos = ypos;
}

SpaceShip::SpaceShip(SpaceShip &other) noexcept {}

SpaceShip &SpaceShip::operator=(SpaceShip &other) noexcept {
    if(&other == this){ return *this; }
    this->xpos = other.xpos;
    this->ypos = other.ypos;
    return *this;
}

SpaceShip::SpaceShip(SpaceShip &&other) noexcept {}

SpaceShip& SpaceShip::operator=(SpaceShip &&other) noexcept {
    if(&other == this){ return *this; }
    this->ypos = other.ypos;
    this->xpos = other.xpos;
    return *this;
}

int SpaceShip::move_left() {
    ypos--;
    return xpos;
}

int SpaceShip::move_right() {
    ypos++;
    return xpos;
}

int SpaceShip::move_up() {
    xpos--;
    return ypos;
}

int SpaceShip::move_down() {
    xpos++;
    return ypos;
}



