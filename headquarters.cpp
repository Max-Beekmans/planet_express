//
// Created by MaxBe on 11/15/2017.
//

#include "headquarters.h"
#include "sector.h"

headquarters::headquarters() = default;

headquarters::headquarters(player& p, IOHandler ioHandler) {
    this->p = p;
    this->io_handler = ioHandler;
}

void headquarters::do_scan() {
    //delete last_scan;
    last_scan = new scan();
    this->last_scan->do_scan();
}

void headquarters::visit_sector(int x, int y) {
    sector s;

    if(last_scan->visited_sectors[x][y].visited){
        s = last_scan->visited_sectors[x][y];
    } else {
        s = {last_scan->scan_result[x][y], p.ship};
        //s = sector(last_scan->scan_result[x][y], p.ship);
        s.visited = true;
        last_scan->visited_sectors[x][y] = s;
    }

    s.print_sector(io_handler);
}

void headquarters::move_ship(int direction) {
    switch (direction) {
        case 0:
            break;
        case 1:
            //move up
            this->p.ship.move_left();
            break;
        case 2:
            //move down
            break;
        case 3:
            //move left
            break;
        case 4:
            //move right
            break;
        default:
            break;
    }
}

void headquarters::move_encounters() {

}




