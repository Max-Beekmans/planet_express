//
// Created by MaxBe on 11/25/2017.
//

#ifndef PLANET_EXPRESS_GAME_H
#define PLANET_EXPRESS_GAME_H


#include "../Helper/IOhandler.h"
#include "../Model/player.h"
#include "headquarters.h"

class game {
public:
    explicit game(IOhandler& handler);
    void run_game();
private:
    bool handle_command(int command_num);
    void do_turn();

    IOhandler handler;
    player player1;
    headquarters hq;
};


#endif //PLANET_EXPRESS_GAME_H
