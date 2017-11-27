//
// Created by MaxBe on 11/25/2017.
//

#ifndef PLANET_EXPRESS_GAME_H
#define PLANET_EXPRESS_GAME_H


#include "Helper/IOHandler.h"
#include "player.h"
#include "headquarters.h"

class game {
public:
    game(IOHandler &handler, player &player);
    void run_game(player &p);
private:
    IOHandler handler;
    headquarters hq;
};


#endif //PLANET_EXPRESS_GAME_H
