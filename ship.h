//
// Created by MaxBe on 11/20/2017.
//

#ifndef PLANET_EXPRESS_SHIP_H
#define PLANET_EXPRESS_SHIP_H

class ship {
public:
    explicit ship(int xpos = 0, int ypos = 0);
    ship(ship &other) noexcept ;
    ship&operator=(ship &&other) noexcept ;
    int move_left();
    int move_right();
    int move_up();
    int move_down();
private:
    int xpos;
    int ypos;
};


#endif //PLANET_EXPRESS_SHIP_H
