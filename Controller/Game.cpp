//
// Created by MaxBe on 11/25/2017.
//

#include <cstring>
#include "Game.h"

void Game::run_game() {
    handler.PrintLine("Welcome to planet express. Now hurry and tell me your name!");
    MyString player_name = MyString(handler.GetLine());
    player1 = Player(player_name.GetValue());
    handler.Print("Great welcome to the club ");
    handler.Print(player1.name.GetValue());
    handler.ClearConsole();

    //Headquarters init task
    hq.do_scan();
    hq.enter_sector(0, 0, 0, 0);
    while(true){
        do_turn();
    }

}

Game::Game(IOHandler &handler) : hq(handler){
    this->handler = handler;
    run_game();
}

bool Game::handle_command(const int command_num) {
    switch(command_num) {
        case 0:
            //WILL LEAK MEMORY SCAN IS NOT CLEARED ON THIS CALL.
            //TEMP ESCAPE
            exit(0);
            //TODO FIX THIS!!!!!!
        case 1:
            player1.ship.move_up();
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 2:
            player1.ship.move_down();
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 3:
            player1.ship.move_left();
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 4:
            player1.ship.move_right();
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 5:
            //pick up package (only near planet)
            return true;
        case 6:
            //look at package (only if package in inventory)
            return true;
        case 7:
            //deliver package (only near delivery planet)
            return true;
        default:
            handler.PrintLine("Invalid command");
            return false;
    }
}

void Game::do_turn() {
    int in = handler.GetInt();
    while(!handle_command(in)){
        handler.PrintLine("can't perform action command");
        in = handler.GetInt();
    };
    handler.PrintDivider();
    handler.Print("Turn: ");
    handler.PrintLine(this->turn_nr);

}
