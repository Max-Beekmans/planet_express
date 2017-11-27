#include "Helper/IOhandler.h"
#include "Controller/game.h"

int main() {
    IOhandler handler{};
    game game {handler};
    return 0;
}