//
// Created by MaxBe on 11/20/2017.
//

#include <random>
#include <ctime>
#include <cstring>
#include "sector.h"

#define SSIZE = 10;

sector::sector(int *arr) {
    generate_sector(arr);
    visited = true;
}

sector::sector(){
    visited = false;
}

sector::sector(sector &&other) noexcept {}

sector &sector::operator=(sector &&other) noexcept {
    if(&other == this){ return *this; }
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

    this->visited = other.visited;
    return *this;
}


struct coordinate {
    int x_pos;
    int y_pos;
};

void sector::generate_sector(int *arr) {
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
        for (int j = 0; j < 10; ++j) {
            h.Print(" ");
            h.Print(i[j].val);
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



