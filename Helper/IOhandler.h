//
// Created by MaxBe on 11/18/2017.
//

#ifndef PLANET_EXPRESS_IOHANDLER_H
#define PLANET_EXPRESS_IOHANDLER_H

#include <iostream>
#include "mString.h"

class IOhandler {
public:
    template <class T>
    void Print(T obj);
    template <class T>
    void PrintLine(T obj);

    mString GetLine();
    int GetInt();

    //not really but just whitespace
    void ClearConsole();
    void PrintDivider();
};

template<class T>
void IOhandler::Print(T obj) {
    std::cout << obj;
}

template<class T>
void IOhandler::PrintLine(T obj) {
    std::cout << obj << std::endl;
}

#endif //PLANET_EXPRESS_IOHANDLER_H
