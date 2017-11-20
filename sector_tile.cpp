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
