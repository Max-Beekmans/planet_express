//
// Created by MaxBe on 11/20/2017.
//

#include "Player.h"

Player::Player() {
    this->name = MyString{"Rodrigo"};
}

Player::Player(const char * input_name){
    if(input_name != nullptr){
        this->name = MyString{input_name};
    } else {
        this->name = MyString{"Rodrigo"};
    }
}

Player::Player(const char *name, SpaceShip ship) {
    this->name = MyString(name);
    this->ship = ship;
}

Player::Player(Player &&other) noexcept {
    this->name = other.name;
    this->ship = other.ship;
}

Player &Player::operator=(const Player &other) noexcept {
    if(&other != this){ return *this; }
    this->name = {other.name};
    this->ship = {other.ship.xpos , other.ship.ypos};
    return *this;
}

Player::Player(Player &other) noexcept {}

Player &Player::operator=(Player &&other) noexcept {
    this->name = other.name;
    this->ship = other.ship;
    return *this;
}


