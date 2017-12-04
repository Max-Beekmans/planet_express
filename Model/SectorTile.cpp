//
// Created by MaxBe on 11/20/2017.
//

#include "SectorTile.h"

SectorTile::SectorTile(char val) {
    this->val = val;
}

bool SectorTile::is_empty() {
    if(val == 'O' || val == '*' || val == '@'){
        return false;
    }
    return true;
    //return val != 'O' || val != '*' || val != '@' || val != 'P';
}

SectorTile::SectorTile(SectorTile &&other) noexcept {
    //this->val = other.val;
    other.val = '\0';
}

SectorTile &SectorTile::operator=(SectorTile &&other) noexcept {
    if(&other == this){ return *this; }
    //delete val;
    val = '\0';
    this->val = other.val;
    return *this;
}

bool SectorTile::is_encounter() {
    return val == '*';
}

bool SectorTile::is_planet() {
    return val == '@';
}
