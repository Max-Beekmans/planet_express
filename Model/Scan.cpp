//
// Created by MaxBe on 11/21/2017.
//

#define OUTTER_SIZE 5
#define INNER_SIZE 3

#include <random>
#include "Scan.h"

//Scan::Scan(const Scan &other) noexcept {}

Scan::Scan() {
    scan_result = nullptr;
}

Scan::~Scan() {
    for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 3; ++k) {
            delete[] scan_result[j][k];
        }
        delete[] scan_result[j];
    }
    delete[] scan_result;
}

Scan::Scan(Scan &&other) noexcept {
//    other.scan_result = nullptr;
}

Scan &Scan::operator=(Scan &&other) noexcept {
    if(&other == this) { return *this; }
//    for (int j = 0; j < 5; ++j) {
//        for (int k = 0; k < 3; ++k) {
//            delete[] scan_result[j][k];
//        }
//        delete[] scan_result[j];
//    }
//    delete[] scan_result;

    this->scan_result = other.scan_result;
    other.scan_result = nullptr;

    return *this;
}

void Scan::print_scan(IOHandler &h) {
    for (int i = 0; i < OUTTER_SIZE; ++i) {
        for (int j = 0; j < OUTTER_SIZE; ++j) {
            for (int k = 0; k < INNER_SIZE; ++k) {
                h.Print(scan_result[i][j][k]);
            }
            h.Print(" ");
        }
        h.PrintLine("");
    }
}

void Scan::do_scan() {
    int ***scan_array;

    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> astroid(0,9);
    std::uniform_int_distribution<int> encounter(0,3);
    std::uniform_int_distribution<int> planet(0,2);

    scan_array = new int**[OUTTER_SIZE];
    for (int i = 0; i < OUTTER_SIZE; ++i) {
        scan_array[i] = new int*[OUTTER_SIZE];
        for (int j = 0; j < OUTTER_SIZE; ++j) {
            scan_array[i][j] = new int[INNER_SIZE];
            //depth || 3rd dimension
            scan_array[i][j][0] = astroid(generator);
            scan_array[i][j][1] = encounter(generator);
            scan_array[i][j][2] = planet(generator);
        }
    }

    this->scan_result = scan_array;
}


//Scan &Scan::operator=(const Scan &other) {
//    return *this;
//}
