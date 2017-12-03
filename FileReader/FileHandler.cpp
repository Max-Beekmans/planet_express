//
// Created by MaxBe on 11/27/2017.
//

#include "FileHandler.h"
#include <iostream>
#include <fstream>

MyString FileHandler::GetLine(const char *file_name) {
    std::ifstream file_stream;
    char line[512];

    file_stream.open(file_name, std::ios::in);

//    while(file_stream.getline(line, sizeof line, ';')){
//        std::cout << line;
//    }

//    while(isspace((unsigned char)*line)) line++;

    char first_char;

    file_stream >> first_char;

    if((!first_char) && first_char == '#'){
        file_stream.ignore(';');
    }

    while (file_stream.getline(line, sizeof line, ';')) {
        std::cout << line;
    }

    return MyString {line};
}
