//
// Created by MaxBe on 11/25/2017.
//

#include <cstring>
#include "game.h"

void game::run_game() {
    handler.PrintLine("Welcome to planet express. Now hurry and tell me your name!");
    mString player_name = mString(handler.GetLine());
    player1 = player(player_name.GetValue());
    handler.Print("Great welcome to the club ");
    handler.Print(player1.name.GetValue());
    handler.PrintDivider();
    handler.ClearConsole();
    hq.do_scan();
    hq.visit_sector(0,0);

    int x = 8;
    while(x != 0){
        x = handler.GetInt();
        handle_command(x);
        handler.ClearConsole();
        hq.visit_sector(0,0);
    }
}

game::game(IOhandler &handler){
    this->handler = handler;
    run_game();
    this->hq = headquarters(player1 , handler);
}

void game::handle_command(const int command_num) {
    switch(command_num) {
        case 0:
            exit(0);
        case 1:
            player1.ship.move_up();
            break;
        case 2:
            player1.ship.move_down();
            break;
        case 3:
            player1.ship.move_left();
            break;
        case 4:
            player1.ship.move_right();
            break;
        case 5:
            //pick up package (only near planet)
            break;
        case 6:
            //look at package (only if package in inventory)
            break;
        case 7:
            //deliver package (only near delivery planet)
            break;
        default:
            break;
    }
}
