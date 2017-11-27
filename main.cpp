#include "Helper/IOhandler.h"
#include "game.h"

int main() {
    IOhandler handler{};
    game game {handler};
    return 0;
}