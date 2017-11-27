//
// Created by MaxBe on 11/25/2017.
//

#ifndef PLANET_EXPRESS_GAME_H
#define PLANET_EXPRESS_GAME_H


#include "Helper/IOhandler.h"
#include "player.h"
#include "headquarters.h"

class game {
public:
    explicit game(IOhandler& handler);
    void run_game();
private:
    IOhandler handler;
    player player1;
    headquarters hq;
};


#endif //PLANET_EXPRESS_GAME_H
