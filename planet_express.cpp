//
// Created by MaxBe on 11/15/2017.
//

#include "planet_express.h"

#include <iostream>
#include <random>
#include <ctime>

void planet_express::do_scan() {
    int ***scan_array;

    for (int i = 0; i < 10; ++i) {
        std::cout << get_random(1,6);
    }

    std::cout << get_random(1,10);
}

int planet_express::get_random(int min, int max) {
    std::default_random_engine generator;
    generator.seed(time(NULL));

    std::uniform_int_distribution<int> distribution(min, max);

    int rand = distribution(generator);

    return rand;
}
