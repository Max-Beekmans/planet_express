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

void MyString::substr(char*& first, char*& second, const char* delim) {
//    const char* delim{ ";" };
    first = strtok(value, delim);
    second = strtok(nullptr, delim);
}

char* MyString::GetToken(const char* delim) {
    char* val = strtok(nullptr, delim);

    if(val != nullptr){
        return val;
    } else {
        return strtok(value , delim);
    }
}

char** MyString::Tokenize(const char* delim) {
    char** arr = new char*[6];
    int i = 0;
    char* tokens[64];
    tokens[i] = strtok(value, delim);
//    while(tokens[i] = strtok(nullptr, delim)){
////        tokens[i] = strtok(nullptr, delim);
//        i++;
//    }

    while(char* p = strtok(nullptr, delim)){
        arr[i] = p;
        i++;
    }

    return arr;
}



