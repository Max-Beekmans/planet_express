//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SECTOR_H
#define PLANET_EXPRESS_SECTOR_H

#include "sector_tile.h"
#include "../Helper/IOhandler.h"

class sector {
public:
    //rof
    sector();
    sector(int arr[3] , int x , int y);
    sector(const sector& other) noexcept;
    sector(sector&& other) noexcept;

    //operators
    sector& operator=(sector&& other) noexcept ;
    sector& operator=(const sector& other) noexcept ;

    void print_sector(IOhandler& h);
    bool place_ship(int ship_x, int ship_y);
    bool visited;
private:
    void generate_sector(const int arr[3]);
    bool try_add(int xpos, int ypos, char value);
    sector_tile sector_map[10][10];
    int sector_x;
    int sector_y;
    int ship_x = 0;
    int ship_y = 0;
};


#endif //PLANET_EXPRESS_SECTOR_H
