//
// Created by MaxBe on 11/20/2017.
//

#include <cstring>
#include "mString.h"

mString::mString() = default;

mString::mString(const char* val) {
    strcpy(value, val);
    //this->value = val;
}

mString::mString(const mString &other) {
    strcpy(this->value, other.value);
}

const char* mString::GetValue() const {
    return this->value;
}

mString &mString::operator=(const mString &other) {
    if(&other == this) { return *this; }
//
    strcpy(value, other.value);
    //this->value = other.GetValue();
    return *this;
}

std::ostream &mString::operator<<(std::ostream &output) {
    return output << this->GetValue();
}

void mString::substr(char*& first, char*& second) {
    const char* delim{ ";" };
    first = strtok(value, delim);
    second = strtok(nullptr, delim);
}



