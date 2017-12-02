#include "Helper/IOHandler.h"
#include "Controller/Game.h"
#include "FileReader/FileHandler.h"

int main() {

    FileHandler fileHandler;
    MyString string = fileHandler.GetLine("../Ontmoetingen.csv");

    //IOHandler handler{};
    //Game game {handler};
    return 0;
}