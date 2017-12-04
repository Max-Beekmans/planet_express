//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SECTOR_TILE_H
#define PLANET_EXPRESS_SECTOR_TILE_H


class SectorTile {
public:
    explicit SectorTile(char val = '.');
    SectorTile(SectorTile &&other) noexcept ;
    SectorTile& operator=(SectorTile&& other) noexcept;
    bool is_empty();
    bool is_encounter();
    bool is_planet();
    char val;
};


#endif //PLANET_EXPRESS_SECTOR_TILE_H
