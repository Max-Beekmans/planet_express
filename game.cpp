//
// Created by MaxBe on 11/25/2017.
//

#include "game.h"

void game::run_game(player &p) {
    mString player_name {handler.GetLine()};
    p = {player_name.GetValue()};
    hq.do_scan();
}

game::game(IOHandler &handler, player &player) {
    this->handler = handler;
    run_game(player);
    this->hq = headquarters(player , handler);
}
