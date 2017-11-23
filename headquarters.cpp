//
// Created by MaxBe on 11/15/2017.
//

#include "headquarters.h"
#include "sector.h"

#include <random>
#include <ctime>

headquarters::headquarters(player &p) {
    this->p = p;
    this->io_handler = {};
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
        s = sector(last_scan->scan_result[x][y]);
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


