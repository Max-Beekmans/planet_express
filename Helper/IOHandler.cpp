//
// Created by MaxBe on 11/27/2017.
//

#include "IOHandler.h"

mString IOHandler::GetLine() {
    char* str = nullptr;
    std::cin >> str;
    mString mstr = {str};
    return mstr;
}