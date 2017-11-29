#include "Helper/IOHandler.h"
#include "Controller/Game.h"

int main() {
    IOHandler handler{};
    Game game {handler};
    return 0;
}