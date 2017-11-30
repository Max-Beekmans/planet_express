//
// Created by MaxBe on 11/25/2017.
//

#ifndef PLANET_EXPRESS_GAME_H
#define PLANET_EXPRESS_GAME_H


#include "../Helper/IOHandler.h"
#include "../Model/Player.h"
#include "Headquarters.h"

class Game {
public:
    explicit Game(IOHandler& handler);
    void run_game();
private:
    bool handle_command(int command_num);
    void do_turn();
    void out_of_field_move(int pos);

    int turn_nr = 0;
    IOHandler handler;
    Player player1;
    Headquarters hq;
};


#endif //PLANET_EXPRESS_GAME_H
