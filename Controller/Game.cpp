//
// Created by MaxBe on 11/25/2017.
//

#include <cstring>
#include "Game.h"

void Game::run_game() {
    handler.PrintLine("Welcome to planet express. Now hurry and tell me your name!");
    MyString player_name = MyString(handler.GetLine());
    SpaceShip spaceShip = SpaceShip(9,0);
    player1 = Player(player_name.GetValue(), spaceShip);
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
        hq.enter_sector(x, y, 9, 0);
        hq.print_current_sector();
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
            if(can_move_ship(player1.ship.xpos , player1.ship.ypos - 1)){
                pos = player1.ship.move_up();
                out_of_field_move(pos);
                hq.update_ship(player1.ship.xpos , player1.ship.ypos);
                return true;
            }
            return false;
        case 2:
            if(can_move_ship(player1.ship.xpos , player1.ship.ypos + 1)){
                pos = player1.ship.move_down();
                out_of_field_move(pos);
                hq.update_ship(player1.ship.xpos , player1.ship.ypos);
                return true;
            }
            return false;
        case 3:
            if(can_move_ship(player1.ship.xpos - 1, player1.ship.ypos)){
                pos = player1.ship.move_left();
                out_of_field_move(pos);
                hq.update_ship(player1.ship.xpos, player1.ship.ypos);
                return true;
            }
            return false;
        case 4:
            if(can_move_ship(player1.ship.xpos + 1, player1.ship.ypos)){
                pos = player1.ship.move_right();
                out_of_field_move(pos);
                hq.update_ship(player1.ship.xpos , player1.ship.ypos);
                return true;
            }
            return false;
        case 5:
            if(hq.can_pickup(player1.ship.xpos, player1.ship.ypos)){
                handler.PrintLine("Obtained Package");
                return true;
            }
            handler.PrintLine("Can't pickup package");
            //pick up package (only near planet)
            return false;
        case 6:
            //look at package (only if package in inventory)
            return true;
        case 7:
            //deliver package (only near delivery planet)
            return true;
        case 8:
            handler.PrintLine("Doing nothing this turn");
            return true;
        default:
            handler.PrintLine("Invalid command");
            return false;
    }
}

void Game::do_turn() {
    int in = handler.GetInt();
    while(!handle_command(in)){
//        handler.PrintLine("can't perform action command");
        in = handler.GetInt();
    };

    hq.print_current_sector();

    this->turn_nr++;
    handler.PrintDivider();
    handler.Print("Turn: ");
    handler.PrintLine(this->turn_nr);
}

void Game::out_of_field_move(int pos) {
    if(pos == player1.ship.xpos){
        if(pos < 0){
            hq.move_left_sector(pos);
            player1.ship.xpos = 9;
        } else if(pos > 9){
            hq.move_right_sector(pos);
            player1.ship.xpos = 0;
        }
    } else {
        if(pos < 0){
            hq.move_up_sector(pos);
            player1.ship.ypos = 9;
        } else if(pos > 9){
            hq.move_down_sector(pos);
            player1.ship.ypos = 0;
        }
    }
}

bool Game::can_move_ship(int target_x, int target_y) {
    if(!hq.can_move(target_x, target_y)){
        handler.Print("Can't move to tile x:  ");
        handler.Print(target_x);
        handler.Print(" y: ");
        handler.PrintLine(target_y);
        return false;
    };
    return true;
}
