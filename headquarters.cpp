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
    int ***scan_array;

    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> astroid(0,9);
    std::uniform_int_distribution<int> encounter(0,3);
    std::uniform_int_distribution<int> planet(0,2);

    scan_array = new int**[5];
    for (int i = 0; i < 5; ++i) {
        scan_array[i] = new int*[5];
        for (int j = 0; j < 5; ++j) {
            scan_array[i][j] = new int[3];
            //depth || 3rd dimension
            scan_array[i][j][0] = astroid(generator);
            scan_array[i][j][1] = encounter(generator);
            scan_array[i][j][2] = planet(generator);
            for (int k = 0; k < 3; ++k) {
            }
        }
    }

    this->last_scan = scan_array;
}

void headquarters::visit_sector(int x, int y) {
    sector s;

    if(visited_sectors[x][y].visited){
        s = visited_sectors[x][y];
    } else {
        s = sector(last_scan[x][y]);
        visited_sectors[x][y] = s;
        s.visited = true;
    }

    s.print_sector(io_handler);
}


