//
// Created by MaxBe on 11/27/2017.
//

#include "IOhandler.h"

mString IOhandler::GetLine() {
    char str[64];
    std::cin >> str;
    mString mstr = {str};
    return mstr;
}

void IOhandler::ClearConsole() {
    for (int i = 0; i < 50; ++i) {
        std::cout << '\n';
    }
    std::cout << std::endl;
}

void IOhandler::PrintDivider() {
    std::cout << std::endl << "_____________________________________________" << std::endl;
}
