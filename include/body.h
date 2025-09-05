//
// Created by John Alex on 02/08/2025.
//

#ifndef BODY_H
#define BODY_H
#include "../include/vector.h"
#include <iostream>

class Body {
    double mass;
    double radius;
    Vector velocity;
    Vector position;

    public:
        Body(double m, double r, const Vector &v, const Vector &p);

        [[nodiscard]] Vector &getVelocity();

        [[nodiscard]] Vector &getPosition();

        [[nodiscard]] double getMass() const;

        [[nodiscard]] double getRadius() const;
};

std::ostream &operator<<(std::ostream &os, const Body &bd);

#endif // BODY_H
