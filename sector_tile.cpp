//
// Created by MaxBe on 11/20/2017.
//

#include "sector_tile.h"

sector_tile::sector_tile(char val) {
    this->val = val;
}

bool sector_tile::is_empty() {
    return val != 'O' || val != '*' || val != '@' || val != 'P';
}

sector_tile::sector_tile(sector_tile &&other) noexcept {
    //this->val = other.val;
    other.val = '\0';
}

sector_tile &sector_tile::operator=(sector_tile &&other) noexcept {
    if(&other == this){ return *this; }
    //delete val;
    val = '\0';
    this->val = other.val;
    return *this;
}
