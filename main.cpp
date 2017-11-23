#include "Helper/IOHandler.h"
#include "ship.h"
#include "headquarters.h"



int main() {

    ship s;
    player p{"Alberto"};
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