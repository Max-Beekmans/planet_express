//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_MSTRING_H
#define PLANET_EXPRESS_MSTRING_H

#include <iostream>
#include <ostream>

class MyString {
public:
    MyString();
    MyString(const char* val);
    MyString(const MyString& other);

    MyString& operator=(const MyString& other);
    std::ostream &operator<<(std::ostream& output);

    const char* GetValue() const;
    void substr(char*& first, char*& second, const char* delim = ";");
    char* GetToken(const char* delim);
    char** Tokenize(char**& tokens, const char* delim);
private:
    char value[128];
};


#endif //PLANET_EXPRESS_MSTRING_H
