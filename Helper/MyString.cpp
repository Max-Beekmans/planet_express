//
// Created by MaxBe on 11/20/2017.
//

#include <cstring>
#include "MyString.h"

MyString::MyString() = default;

MyString::MyString(const char* val) {
    strcpy(value, val);
    //this->value = val;
}

MyString::MyString(const MyString &other) {
    strcpy(this->value, other.value);
}

const char* MyString::GetValue() const {
    return this->value;
}

MyString &MyString::operator=(const MyString &other) {
    if(&other == this) { return *this; }
//
    strcpy(value, other.value);
    //this->value = other.GetValue();
    return *this;
}

std::ostream &MyString::operator<<(std::ostream &output) {
    return output << this->GetValue();
}

void MyString::substr(char*& first, char*& second) {
    const char* delim{ ";" };
    first = strtok(value, delim);
    second = strtok(nullptr, delim);
}



