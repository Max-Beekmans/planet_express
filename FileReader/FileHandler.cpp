//
// Created by MaxBe on 11/27/2017.
//

#include "FileHandler.h"

#include <random>
#include <ctime>
#include <iostream>
#include <fstream>

MyString FileHandler::GetLine(const char *file_name) {
    std::ifstream file_stream;
    file_stream.open(file_name);

    char line[25][512];
    int i = 0;
    int min = 0;
    int max = 25;
    //file_stream >> line[i]
    while(file_stream.getline(line[i] , sizeof line[i])){
        if(line[i][0] == '#'){
            min++;
        }
        //std::cout << line[i] << std::endl;
        i++;
    }

    file_stream.close();

    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> rand_line(min,max);

    //TODO replace for rand line ( where min escapes # lines)
    MyString string = MyString(line[rand_line(generator)]);
    return MyString {line[15]};
}

Encounter FileHandler::GetRandomEncounter(int character) {

    //character 1 (Fry), 2 (Leela), 3 (Bender)

    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> coin_toss(0,1);


    MyString string = GetLine("../Ontmoetingen.csv");



    return ParseEncounter(string, character, coin_toss(generator));
    //return Encounter{string};
}

Encounter FileHandler::ParseEncounter(MyString string, int character, int coin) {
    Encounter enc;
    char** result = string.Tokenize(";");

    for (int i = 0; i < 6; ++i) {
        condition c = this->parse_condition(result[i]);

        if(i == 0){
            enc.description = MyString{result[i]};
        } else if(i == 1){
            enc.condition.damage_taken = c.damage_taken;
            enc.condition.damage_dealt = c.damage_dealt;
        } else if(i == 2){
            enc.condition_text = result[i];
        } else if(i == 3){
            enc.condition.damage_taken = c.damage_taken;
            enc.condition.damage_dealt = c.damage_dealt;
        } else if(i == 4){

        } else if(i == 5){

        } else if(i == 6){

        }
    }

    delete[] result;
    return enc;
}

FileHandler::condition FileHandler::parse_condition(char* string) {
    condition c = condition();
    int i = 0;
    int j = 0;
    char* end;
    char digit[2];
    while(string[i] != '\0'){
        if(isdigit(string[i])){
            digit[j++] = string[i];
        } else if(string[i] == '-'){
            c.damage_dealt = std::strtol(digit , &end, 0);
            digit[0] = '\0';
            j = 0;
        } else if(string[i] == ']'){
            c.damage_taken = std::strtol(digit , &end, 0);
            digit[0] = '\0';
            j = 0;
        }
        i++;
    }

   // int dig = std::strtol(digit , &end, 0);

//    while(string[i] != ']'){
//        char digit[2];
//        int j = 0;
//        if(isdigit(string[i])){
//            digit[j] = string[i];
//            j++;
//        }
//        i++;
//    }

    return c;
}
