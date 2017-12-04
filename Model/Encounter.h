//
// Created by Max on 12/2/2017.
//

#ifndef PLANET_EXPRESS_ENCOUNTER_H
#define PLANET_EXPRESS_ENCOUNTER_H


#include "../Helper/MyString.h"

class Encounter {
public:
    Encounter();

    struct encounter_condition {
        int damage_taken;
        int damage_dealt;
    };
    MyString description;
    encounter_condition condition;
    MyString condition_text;

};


#endif //PLANET_EXPRESS_ENCOUNTER_H
