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
    //rof
    sector();
    sector(int arr[3], ship& ship);
    sector(const sector& other) noexcept;
    sector(sector&& other) noexcept;

    //operators
    sector& operator=(sector&& other) noexcept ;
    sector& operator=(const sector& other) noexcept ;

    void print_sector(IOHandler& h);
    bool visited;
private:
    void generate_sector(const int arr[3]);
    void place_ship(ship& ship);
    bool try_add(int xpos, int ypos, char value);
    sector_tile sector_map[10][10];
    ship ship;
};


#endif //PLANET_EXPRESS_SECTOR_H
