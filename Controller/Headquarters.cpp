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
        s = {last_scan->scan_result[x][y] , x , y,  ship_x, ship_y};
        //s = Sector(last_scan->scan_result[x][y], p.ship);
        s.visited = true;
        last_scan->visited_sectors[x][y] = s;
    }

    this->current_sector = s;

    update_ship(ship_x, ship_y);
    //s.place_ship(ship_x , ship_y);
    //s.print_sector(io_handler);
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

void Headquarters::move_right_sector(int ship_y) {
    int x = current_sector.sector_x;
    if(x > 4){
        //abandon
    }
    enter_sector(x + 1 , current_sector.sector_y , 0, ship_y - 1);
}

void Headquarters::move_left_sector(int ship_y) {
    int x = current_sector.sector_x;
    if(x < 0){
        //abandon
    }
    enter_sector(x - 1 , current_sector.sector_y , 9, ship_y - 1);
}

void Headquarters::move_up_sector(int ship_x) {
    int y = current_sector.sector_y;
    if(y < 0){
        //abandon
    }
    enter_sector(current_sector.sector_x, y - 1, ship_x - 1, 0);
}

void Headquarters::move_down_sector(int ship_x) {
    int y = current_sector.sector_y;
    if(y > 4){
        //abandon
    }
    enter_sector(current_sector.sector_x, y + 1, ship_x - 1, 9);
}

bool Headquarters::can_move(int x, int y) {
    return current_sector.can_add(x, y);
}








