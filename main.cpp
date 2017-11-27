#include "spaceShip.h"
#include "Helper/IOHandler.h"
#include "headquarters.h"
#include "game.h"

int main() {

    spaceShip s {};
    player p{"Alberto" , s};
    IOHandler handler{};
    game game = {handler, p};
    return 0;
}