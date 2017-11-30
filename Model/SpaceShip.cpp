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

//ypos = col , xpos = row
int SpaceShip::move_left() {
    xpos--;
    return xpos;
}

int SpaceShip::move_right() {
    xpos++;
    return xpos;
}

int SpaceShip::move_up() {
    ypos--;
    return ypos;
}

int SpaceShip::move_down() {
    ypos++;
    return ypos;
}



