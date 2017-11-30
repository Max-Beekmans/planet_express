//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SECTOR_H
#define PLANET_EXPRESS_SECTOR_H

#include "SectorTile.h"
#include "../Helper/IOHandler.h"

class Sector {
public:
    //rof
    Sector();
    Sector(int arr[3] , int x , int y);
    Sector(const Sector& other) noexcept;
    Sector(Sector&& other) noexcept;

    //operators
    Sector& operator=(Sector&& other) noexcept ;
    Sector& operator=(const Sector& other) noexcept ;

    void print_sector(IOHandler& h);
    bool place_ship(int ship_x, int ship_y);
    bool visited;
    int sector_x;
    int sector_y;
private:
    void generate_sector(const int arr[3]);
    bool try_add(int xpos, int ypos, char value);
    SectorTile sector_map[10][10];
    int ship_x = 0;
    int ship_y = 0;
};


#endif //PLANET_EXPRESS_SECTOR_H
