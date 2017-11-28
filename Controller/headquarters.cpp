//
// Created by MaxBe on 11/15/2017.
//

#include "headquarters.h"
#include "../Model/sector.h"

headquarters::headquarters(IOhandler ioHandler) : io_handler(ioHandler) {}

void headquarters::do_scan() {
    //delete last_scan;
    last_scan = new scan();
    this->last_scan->do_scan();
}

void headquarters::enter_sector(int x, int y, int ship_x, int ship_y) {
    sector s;

    if(last_scan->visited_sectors[x][y].visited){
        s = last_scan->visited_sectors[x][y];
    } else {
        s = {last_scan->scan_result[x][y] , x , y};
        //s = sector(last_scan->scan_result[x][y], p.ship);
        s.visited = true;
        last_scan->visited_sectors[x][y] = s;
    }

    this->current_sector = s;

    s.place_ship(ship_x , ship_y);
    s.print_sector(io_handler);
}

bool headquarters::update_ship(int x, int y) {
    if(current_sector.place_ship(x , y)){
        io_handler.ClearConsole();
        current_sector.print_sector(io_handler);
        return true;
    };
    return false;
}

void headquarters::leave_sector() {

}

void headquarters::update_encounters() {

}








