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
    explicit sector(int arr[3]);
    sector(const sector& other) noexcept;
    sector(sector&& other) noexcept;

    //operators
    sector& operator=(sector&& other) noexcept ;
    sector& operator=(const sector &other) noexcept ;

    void print_sector(IOHandler& h);
    bool visited;
private:
    void generate_sector(int arr[3]);
    bool try_add(int xpos, int ypos, char value);
    sector_tile sector_map[10][10];
};


#endif //PLANET_EXPRESS_SECTOR_H
