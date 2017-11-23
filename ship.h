//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SHIP_H
#define PLANET_EXPRESS_SHIP_H


#include "sector.h"

class ship {
public:
    ship(int xpos, int ypos);

    int move_left();
    int move_right();
    int move_up();
    int move_down();
private:
    int xpos;
    int ypos;
};


#endif //PLANET_EXPRESS_SHIP_H
