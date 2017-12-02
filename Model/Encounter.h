//
// Created by Max on 12/2/2017.
//

#ifndef PLANET_EXPRESS_ENCOUNTER_H
#define PLANET_EXPRESS_ENCOUNTER_H


#include "../Helper/MyString.h"

class Encounter {
public:
    Encounter(MyString description);

    struct encounter_condition{
        int min;
        int max;
    };
    MyString description;
    encounter_condition condition;
    int encounter_condition_max;
    MyString condition_text;

};


#endif //PLANET_EXPRESS_ENCOUNTER_H
