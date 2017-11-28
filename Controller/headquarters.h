//
// Created by MaxBe on 11/15/2017.
//

#ifndef PLANET_EXPRESS_PLANET_EXPRESS_H
#define PLANET_EXPRESS_PLANET_EXPRESS_H


#include <random>

#include "../Helper/IOhandler.h"
#include "../Model/scan.h"

class headquarters {
public:
    explicit headquarters(IOhandler ioHandler);
    void do_scan();
    void enter_sector(int x, int y, int ship_x, int ship_y);
    void leave_sector();

    bool update_ship(int x, int y);
    void update_encounters();
    scan* last_scan = new scan();
private:
    IOhandler io_handler;
    sector current_sector;
};


#endif //PLANET_EXPRESS_PLANET_EXPRESS_H
