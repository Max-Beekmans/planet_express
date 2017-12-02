//
// Created by MaxBe on 11/20/2017.
//

#include <random>
#include <ctime>
#include <cstring>

#include "Sector.h"

Sector::Sector(int *arr, int x, int y, int ship_x, int ship_y) {
    this->sector_x = x;
    this->sector_y = y;
    generate_sector(arr);
    visited = true;
}

Sector::Sector(){
    visited = false;
}

//Sector::Sector(Sector &&other) noexcept {}

Sector &Sector::operator=(Sector &&other) noexcept {
    if(&other == this){ return *this; }
    for (int i = 0; i < 10; ++i) {
        memcpy(this->sector_map[i] , other.sector_map[i] , 10);
    }
    this->visited = other.visited;
    this->sector_x = other.sector_x;
    this->sector_y = other.sector_y;
    return *this;
}

Sector::Sector(const Sector &other) noexcept {}

Sector &Sector::operator=(const Sector &other) noexcept {
    if(&other == this){ return *this; }
    //delete?
    for (int i = 0; i < 10; ++i) {
        memcpy(this->sector_map[i] , other.sector_map[i] , 10);
    }
    this->visited = other.visited;
    this->sector_x = other.sector_x;
    this->sector_y = other.sector_y;
    return *this;
}

bool Sector::place_ship(int ship_x, int ship_y) {
    if(try_add(ship_x , ship_y , 'P')){
        if(ship_x != this->ship_x || ship_y != this->ship_y){
            sector_map[this->ship_y][this->ship_x].val = '.';
            this->ship_x = ship_x;
            this->ship_y = ship_y;
        }
        return true;
    }
    return false;
}

struct coordinate {
    int x_pos;
    int y_pos;
};

void Sector::generate_sector(const int *arr, int ship_x, int ship_y) {
    coordinate astroid_arr[arr[0]];
    coordinate encounter_arr[arr[1]];
    coordinate planet_arr[arr[2]];
    
    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> map_size(0,9);

    try_add(ship_x, ship_y, 'P');

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

void Sector::print_sector(IOHandler &h) {
    for (auto &i : this->sector_map) {
        for (auto &j : i) {
            h.Print(" ");
            h.Print(j.val);
            h.Print(" ");
        }
        h.PrintLine(' ');
    }
}

bool Sector::can_add(int xpos, int ypos) {
    return sector_map[ypos][xpos].is_empty();
}

bool Sector::try_add(int xpos, int ypos, char value) {
    if(can_add(xpos, ypos)){
        sector_map[ypos][xpos].val = value;
        return true;
    } else {
        return false;
    }
}







