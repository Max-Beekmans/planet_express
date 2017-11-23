//
// Created by MaxBe on 11/20/2017.
//

#include "ship.h"

ship::ship(int xpos, int ypos) {
    this->xpos = xpos;
    this->ypos = ypos;
}

ship::ship(ship &other) noexcept {}

ship& ship::operator=(ship&& other) noexcept {
    this->ypos = other.ypos;
    this->xpos = other.xpos;
    return *this;
}

int ship::move_left() {
    return xpos - 1;
}

int ship::move_right() {
    return xpos + 1;
}

int ship::move_up() {
    return ypos - 1;
}

int ship::move_down() {
    return ypos + 1;
}



