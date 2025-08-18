//
// Created by John Alex on 02/08/2025.
//

#ifndef BODY_H
#define BODY_H
#include <iostream>
#include "../include/coordinates.h"

class Body {
    double mass;
    double radius;
    Coordinate velocity;
    Coordinate position;

    public:
        Body(double m, double r, const Coordinate &v, const Coordinate &p);

        [[nodiscard]] Coordinate &getVelocity();

        [[nodiscard]] Coordinate &getPosition();

        [[nodiscard]] double getMass() const;

        [[nodiscard]] double getRadius() const;
};

std::ostream &operator<<(std::ostream &os, const Body &bd);

#endif // BODY_H
