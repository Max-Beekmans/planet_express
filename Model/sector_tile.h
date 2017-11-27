//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SECTOR_TILE_H
#define PLANET_EXPRESS_SECTOR_TILE_H


class sector_tile {
public:
    explicit sector_tile(char val = '.');
    sector_tile(sector_tile &&other) noexcept ;
    sector_tile& operator=(sector_tile&& other) noexcept;
    bool is_empty();
    char val;
};


#endif //PLANET_EXPRESS_SECTOR_TILE_H
