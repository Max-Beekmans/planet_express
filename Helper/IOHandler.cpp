//
// Created by MaxBe on 11/27/2017.
//

#include "IOHandler.h"

MyString IOHandler::GetLine() {
    char str[64];
    std::cin >> str;
    MyString mstr = {str};
    return mstr;
}

int IOHandler::GetInt() {
    int x = 0;
    std::cin >> x;
    return x;
}


void IOHandler::ClearConsole() {
    for (int i = 0; i < 10; ++i) {
        std::cout << '\n';
    }
    std::cout << std::endl;
}

void IOHandler::PrintDivider() {
    std::cout << std::endl << "_____________________________________________" << std::endl;
}

