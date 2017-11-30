//
// Created by MaxBe on 11/15/2017.
//

#ifndef PLANET_EXPRESS_PLANET_EXPRESS_H
#define PLANET_EXPRESS_PLANET_EXPRESS_H


#include <random>

#include "../Helper/IOHandler.h"
#include "../Model/Scan.h"

class Headquarters {
public:
    explicit Headquarters(IOHandler ioHandler);
    void do_scan();
    void enter_sector(int x, int y, int ship_x, int ship_y);
    void leave_sector();

    bool update_ship(int x, int y);
    void update_encounters();
    void move_left_sector(int ship_y);
    void move_right_sector(int ship_y);
    void move_up_sector(int ship_x);
    void move_down_sector(int ship_x);

    Scan* last_scan = new Scan();
private:
    IOHandler io_handler;
    Sector current_sector;
};


#endif //PLANET_EXPRESS_PLANET_EXPRESS_H
