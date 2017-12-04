//
// Created by MaxBe on 11/27/2017.
//

#ifndef PLANET_EXPRESS_FILE_HANDLER_H
#define PLANET_EXPRESS_FILE_HANDLER_H


#include "../Helper/MyString.h"
#include "../Model/Encounter.h"

class FileHandler {
public:

    Encounter GetRandomEncounter(int character);
    //Planet GetPlanet();
    MyString GetLine(const char* file_name);

private:
    Encounter ParseEncounter(MyString string, int character, int coin);

};


#endif //PLANET_EXPRESS_FILE_HANDLER_H
