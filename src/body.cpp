//
// Created by John Alex on 04/08/2025.
//

#include "../include/body.h"
#include "../include/vector.h"

Body::Body(const double m, const double r, const Vector &v, const Vector &p) {
    mass = m;
    radius = r;
    velocity = v;
    position = p;
}


Vector &Body::getVelocity() { return velocity; }

Vector &Body::getPosition() { return position; }

double Body::getMass() const { return mass; }

double Body::getRadius() const { return radius; }

