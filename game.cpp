//
// Created by MaxBe on 11/25/2017.
//

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
    mString command = mString(handler.GetLine());
    char* command_c = nullptr;
    char* param = nullptr;
    command.substr(command_c , param);
    handler.PrintLine(command_c);
    handler.PrintLine(param);
}

game::game(IOhandler &handler){
    this->handler = handler;
    run_game();
    this->hq = headquarters(player1 , handler);
}
