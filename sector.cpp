//
// Created by MaxBe on 11/20/2017.
//

#include <random>
#include <ctime>
#include <cstring>

#include "sector.h"

sector::sector(int *arr, ship& ship) {
    this->ship = ship;
    generate_sector(arr);
    visited = true;
}

sector::sector(){
    ship = nullptr;
    visited = false;
}

sector::sector(sector &&other) noexcept {
    this->ship = other.ship;
}

sector &sector::operator=(sector &&other) noexcept {
    if(&other == this){ return *this; }
    this->ship = nullptr;
    //delete?
    for (int i = 0; i < 10; ++i) {
        memcpy(this->sector_map[i] , other.sector_map[i] , 10);
    }
    return *this;
}

sector::sector(const sector &other) noexcept {}

sector &sector::operator=(const sector &other) noexcept {
    if(&other == this){ return *this; }
    //delete?
    for (int i = 0; i < 10; ++i) {
        memcpy(this->sector_map[i] , other.sector_map[i] , 10);
    }
    this->ship = other.ship;
    this->visited = other.visited;
    return *this;
}

void sector::place_ship(ship& ship) {
    int x = ship.xpos;
    int y = ship.ypos;
    this->sector_map[x][y] = 'P';
}

struct coordinate {
    int x_pos;
    int y_pos;
};

void sector::generate_sector(const int *arr) {
    coordinate astroid_arr[arr[0]];
    coordinate encounter_arr[arr[1]];
    coordinate planet_arr[arr[2]];
    
    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> map_size(0,9);

    //generate astroids
    for (int i = 0; i < arr[0]; ++i) {
        int x = astroid_arr[i].x_pos = map_size(generator);
        int y = astroid_arr[i].y_pos = map_size(generator);

        if(!try_add(x, y, 'O')){
            i--;
        };
    }

    //generate encounters
    for (int i = 0; i < arr[1]; ++i) {
        int x = encounter_arr[i].x_pos = map_size(generator);
        int y = encounter_arr[i].y_pos = map_size(generator);

        if(!try_add(x, y, '*')){
            i--;
        };
    }

    //generate planets
    for (int i = 0; i < arr[2]; ++i) {
        int x = planet_arr[i].x_pos = map_size(generator);
        int y = planet_arr[i].y_pos = map_size(generator);

        if(!try_add(x, y, '@')){
            i--;
        };
    }
}

void sector::print_sector(IOHandler &h) {
    for (auto &i : this->sector_map) {
        for (auto &j : i) {
            h.Print(" ");
            h.Print(j.val);
            h.Print(" ");
        }
        h.PrintLine(' ');
    }
}

bool sector::try_add(int xpos, int ypos, char value) {
    if(sector_map[xpos][ypos].is_empty()){
        sector_map[xpos][ypos].val = value;
        return true;
    } else {
        return false;
    }
}







