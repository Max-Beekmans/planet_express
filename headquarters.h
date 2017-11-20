//
// Created by MaxBe on 11/15/2017.
//

#ifndef PLANET_EXPRESS_PLANET_EXPRESS_H
#define PLANET_EXPRESS_PLANET_EXPRESS_H


#include <random>
#include "ship.h"
#include "player.h"
#include "Helper/IOHandler.h"
#include "sector.h"

class headquarters {
public:
    headquarters(player& p);
    void do_scan();
    int*** last_scan;
    void visit_sector(int arr[3]);
    void print_sector(sector s);
private:
    player p;
    IOHandler io_handler;
    //int get_random(int min, int max);


};


#endif //PLANET_EXPRESS_PLANET_EXPRESS_H
