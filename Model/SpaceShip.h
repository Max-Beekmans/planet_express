//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SHIP_H
#define PLANET_EXPRESS_SHIP_H

class SpaceShip {
public:
    SpaceShip(int xpos = 0, int ypos = 0);
    SpaceShip(SpaceShip &other) noexcept ;
    SpaceShip(SpaceShip &&other) noexcept ;
    SpaceShip&operator=(SpaceShip &&other) noexcept ;
    SpaceShip&operator=(SpaceShip &other) noexcept ;
    int move_left();
    int move_right();
    int move_up();
    int move_down();
    int xpos;
    int ypos;
};


#endif //PLANET_EXPRESS_SHIP_H
