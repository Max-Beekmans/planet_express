//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SECTOR_H
#define PLANET_EXPRESS_SECTOR_H

#include "ship.h"
#include "Helper/IOHandler.h"
#include "sector_tile.h"

class sector {
public:
    sector(int arr[3]);
    void print_sector(IOHandler& h);
private:
    void generate_sector(int arr[3]);
    sector_tile sector_map[10][10];
    bool check_duplicates(int* arr, int size);
    bool tryadd(int xpos, int ypos, char value);
};


#endif //PLANET_EXPRESS_SECTOR_H
