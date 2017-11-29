//
// Created by MaxBe on 11/15/2017.
//

#include "Headquarters.h"
#include "../Model/Sector.h"

Headquarters::Headquarters(IOHandler ioHandler) : io_handler(ioHandler) {}

void Headquarters::do_scan() {
    //delete last_scan;
    last_scan = new Scan();
    this->last_scan->do_scan();
    last_scan->print_scan(io_handler);
}

void Headquarters::enter_sector(int x, int y, int ship_x, int ship_y) {
    Sector s;

    if(last_scan->visited_sectors[x][y].visited){
        s = last_scan->visited_sectors[x][y];
    } else {
        s = {last_scan->scan_result[x][y] , x , y};
        //s = Sector(last_scan->scan_result[x][y], p.ship);
        s.visited = true;
        last_scan->visited_sectors[x][y] = s;
    }

    this->current_sector = s;

    s.place_ship(ship_x , ship_y);
    s.print_sector(io_handler);
}

bool Headquarters::update_ship(int x, int y) {
    if(current_sector.place_ship(x , y)){
        io_handler.ClearConsole();
        current_sector.print_sector(io_handler);
        return true;
    };
    return false;
}

void Headquarters::leave_sector() {

}

void Headquarters::update_encounters() {

}








