//
// Created by John Alex on 04/08/2025.
//

#include <utility>

#include "../include/body.h"
#include "../include/vector.h"

Body::Body(const std::string &bodyName, const double m, const double r,
           Vector &a, Vector &v, Vector &p) {
  label = bodyName;
  mass = m;
  radius = r;
  acceleration = a;
  velocity = v;
  position = p;
}

Vector &Body::getAcceleration() { return acceleration; }
void Body::setAcceleration(Vector a) { acceleration = a; }

Vector &Body::getVelocity() { return velocity; }

void Body::setVelocity(Vector v) { velocity = v; }

Vector &Body::getPosition() { return position; }

void Body::setPosition(const Vector &new_pos) { position = new_pos; }

double Body::getMass() { return mass; }

double Body::getRadius() { return radius; }

std::string Body::getLabel() { return label; }
