//
// Created by MaxBe on 11/21/2017.
//

#ifndef PLANET_EXPRESS_SCAN_H
#define PLANET_EXPRESS_SCAN_H

#include "sector.h"
#include "../Helper/IOhandler.h"


class scan {
public:
    //rof
    scan();
    ~scan();
    //scan(const scan& other) noexcept ;
    scan(scan&& other) noexcept ;

    //operators
    scan&operator=(scan&& other) noexcept ;
    //scan&operator=(const scan& other) noexcept ;

    void do_scan();
    void print_scan(IOhandler& h);
    int*** scan_result;
    sector visited_sectors[5][5];
private:

};


#endif //PLANET_EXPRESS_SCAN_H
