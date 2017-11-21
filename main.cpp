#include "headquarters.h"
#include "Helper/IOHandler.h"

int main() {

    player p{"Alberto"};
    headquarters hq{p};

    IOHandler handler{};
    hq.do_scan();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 3; ++k) {
                handler.Print(hq.last_scan[i][j][k]);
            }
            handler.Print(" ");
        }
        handler.PrintLine("");
    }

    hq.visit_sector(0,3);

    hq.visit_sector(0,3);

    return 0;
}