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
    handler.PrintLine("Scanning....");
    hq.do_scan();
    handler.PrintLine("I've found 25 sectors on the scan!");
    handler.PrintLine("Please enter an x and an y");
    int x = handler.GetInt();
    int y = handler.GetInt();
    if(x == 0 || y == 0){
        hq.enter_sector(x, y, 0, 0);
    } else {
        handler.PrintLine("can only enter outside sectors");
    }

    while(true){
        do_turn();
    }

}

Game::Game(IOHandler &handler) : hq(handler){
    this->handler = handler;
    run_game();
}

bool Game::handle_command(const int command_num) {
    int pos = 0;
    switch(command_num) {
        case 0:
            //WILL LEAK MEMORY SCAN IS NOT CLEARED ON THIS CALL.
            //TEMP ESCAPE
            exit(0);
            //TODO FIX THIS!!!!!!
        case 1:
            pos = player1.ship.move_up();
            out_of_field_move(pos);
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 2:
            pos = player1.ship.move_down();
            out_of_field_move(pos);
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 3:
            pos = player1.ship.move_left();
            out_of_field_move(pos);
            return hq.update_ship(player1.ship.xpos , player1.ship.ypos);
        case 4:
            pos = player1.ship.move_right();
            out_of_field_move(pos);
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

    this->turn_nr++;
    handler.PrintDivider();
    handler.Print("Turn: ");
    handler.PrintLine(this->turn_nr);

}

void Game::out_of_field_move(int pos) {
    if(pos == player1.ship.xpos){
        if(pos < 0){
            hq.move_left_sector(pos);
        } else if(pos > 10){
            hq.move_right_sector(pos);
        }
    } else {
        if(pos < 0){
            hq.move_up_sector(pos);
        } else if(pos > 10){
            hq.move_down_sector(pos);
        }
    }
}
