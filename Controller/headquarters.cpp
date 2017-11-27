//
// Created by MaxBe on 11/15/2017.
//

#include "headquarters.h"
#include "../Model/sector.h"

headquarters::headquarters() = default;

headquarters::headquarters(player& player, IOhandler ioHandler) : p(player) , io_handler(ioHandler) {}

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


void headquarters::move_encounters() {

}






