//
// Created by MaxBe on 11/18/2017.
//

#ifndef PLANET_EXPRESS_IOHANDLER_H
#define PLANET_EXPRESS_IOHANDLER_H

#include <iostream>

class IOHandler {
public:
    template <class T>
    void Print(T obj);
    template <class T>
    void PrintLine(T obj);

    //char* GetLine();
};

template<class T>
void IOHandler::Print(T obj) {
    std::cout << obj;
}

template<class T>
void IOHandler::PrintLine(T obj) {
    std::cout << obj << std::endl;
}

//char *IOHandler::GetLine() {
//    return nullptr;
//}

#endif //PLANET_EXPRESS_IOHANDLER_H
