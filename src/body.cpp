//
// Created by John Alex on 04/08/2025.
//

#include "../include/body.h"
#include "../include/coordinates.h"

Body::Body(const double m, const double r, const Coordinate &v, const Coordinate &p) {
    mass = m;
    radius = r;
    velocity = v;
    position = p;
}


Coordinate &Body::getVelocity() { return velocity; }

Coordinate &Body::getPosition() { return position; }

double Body::getMass() const { return mass; }

double Body::getRadius() const { return radius; }

