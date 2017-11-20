//
// Created by MaxBe on 11/20/2017.
//

#include "mString.h"

mString::mString(const char *val) {
    this->value = val;
}

mString::mString(const mString &other) {
    this->value = other.value;
}

mString::mString() {
    this->value = nullptr;
}



