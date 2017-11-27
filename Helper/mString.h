//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_MSTRING_H
#define PLANET_EXPRESS_MSTRING_H

#include <iostream>
#include <ostream>

class mString {
public:
    mString();
    mString(const char* val);
    mString(const mString& other);

    mString& operator=(const mString& other);
    std::ostream &operator<<(std::ostream& output);

    const char* GetValue() const;
    void substr(char*& first, char*& second);
private:
    char value[128];
};


#endif //PLANET_EXPRESS_MSTRING_H
