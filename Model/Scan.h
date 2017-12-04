//
// Created by MaxBe on 11/21/2017.
//

#ifndef PLANET_EXPRESS_SCAN_H
#define PLANET_EXPRESS_SCAN_H

#include "Sector.h"
#include "../Helper/IOHandler.h"


class Scan {
public:
    //rof
    Scan();
    ~Scan();
    //Scan(const Scan& other) noexcept ;
    Scan(Scan&& other) noexcept ;

    //operators
    Scan&operator=(Scan&& other) noexcept ;
    //Scan&operator=(const Scan& other) noexcept ;

    void do_scan();
    void print_scan(IOHandler& h);
    int*** scan_result;
    Sector visited_sectors[5][5];
private:

};


#endif //PLANET_EXPRESS_SCAN_H
