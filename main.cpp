#include "include/body.h"
#include <iostream>

int main () {
    Velocity vel(2.0,1.0, 0);
    Position pos(0, 0, 0 );
    Body body(10, 5, vel, pos);
    std::cout << body << std::endl;
    body.atTime(10);
    std::cout << body << std::endl;
    return 0;
};