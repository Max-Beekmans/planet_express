//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SHIP_H
#define PLANET_EXPRESS_SHIP_H

class spaceShip {
public:
    spaceShip(int xpos = 0, int ypos = 0);
    spaceShip(spaceShip &other) noexcept ;
    spaceShip(spaceShip &&other) noexcept ;
    spaceShip&operator=(spaceShip &&other) noexcept ;
    spaceShip&operator=(spaceShip &other) noexcept ;
    int move_left();
    int move_right();
    int move_up();
    int move_down();
    int xpos;
    int ypos;
};


#endif //PLANET_EXPRESS_SHIP_H
