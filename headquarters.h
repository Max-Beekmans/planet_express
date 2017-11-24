//
// Created by MaxBe on 11/15/2017.
//

#ifndef PLANET_EXPRESS_PLANET_EXPRESS_H
#define PLANET_EXPRESS_PLANET_EXPRESS_H


#include <random>

#include "spaceShip.h"
#include "player.h"
#include "Helper/IOHandler.h"
#include "sector.h"
#include "scan.h"

class headquarters {
public:
    explicit headquarters(player& p);
    void do_scan();
    void visit_sector(int x, int y);
    //direction ( 1 = up, 2 = down, 3 = left, 4 = right )
    void move_ship(int direction);
    void move_encounters();
    scan* last_scan;
private:
    player p;
    IOHandler io_handler;
};


#endif //PLANET_EXPRESS_PLANET_EXPRESS_H
