#include "Helper/IOHandler.h"
#include "Controller/Game.h"
#include "FileReader/FileHandler.h"

int main() {

    FileHandler fileHandler;
    MyString string = fileHandler.GetLine("../Ontmoetingen.csv");

    Encounter encounter = fileHandler.GetRandomEncounter(1);


    IOHandler handler{};
    //handler.PrintLine(string.GetValue());
    Game game {handler};
    return 0;
}