//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_MSTRING_H
#define PLANET_EXPRESS_MSTRING_H

class mString {
public:
    mString();
    mString(const char* val);
    mString(const mString& other);

    mString& operator=(const mString& other)
    {
        if(&other == this) { return *this; }

//        delete value;
//        value = other.value;
        return *this;
    }

private:
    const char *value;
};


#endif //PLANET_EXPRESS_MSTRING_H
