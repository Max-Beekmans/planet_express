#include "Helper/IOHandler.h"
#include "spaceShip.h"
#include "headquarters.h"



int main() {

    spaceShip s {};
    player p{"Alberto" , s};
    headquarters hq{p};

    IOHandler handler{};
    hq.do_scan();
    hq.last_scan->print_scan(handler);

    hq.visit_sector(0,3);

    hq.visit_sector(0,3);

    hq.do_scan();

    hq.visit_sector(0,3);
    hq.visit_sector(0,3);

    return 0;
}