//
// Created by John Alex on 04/08/2025.
//

#include "../include/body.h"
#include "../include/utils.h"
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const Vector &vel) {
  const std::vector<double> args = {vel.x, vel.y, vel.z};
  const std::string repr = "(" + join(", ", args) + ")";
  os << repr;
  return os;
}

Vector operator+(const Vector &vec1, const Vector &vec2) {
  double x = vec1.x + vec2.x;
  double y = vec1.y + vec2.y;
  double z = vec1.z + vec2.z;
  const Vector result(x, y, z);
  return result;
}

Vector operator-(const Vector &vec1, const Vector &vec2) {
  double x = vec1.x - vec2.x;
  double y = vec1.y - vec2.y;
  double z = vec1.z - vec2.z;
  const Vector result(x, y, z);
  return result;
}

std::ostream &operator<<(std::ostream &os, const Body &bd) {
  const std::string velPos =
      to_string(bd.getVelocity()) + ", " + to_string(bd.getPosition());
  os << std::format("Body(m: {}, r: {}, ", bd.getMass(), bd.getRadius())
     << velPos << ")";
  return os;
}

Body::Body(const double m, const double r, const Vector &v, const Vector &p) {
  mass = m;
  radius = r;
  velocity = v;
  position = p;
}

Vector Body::getVelocity() const { return velocity; }

Vector Body::getPosition() const { return position; }

double Body::getMass() const { return mass; }

double Body::getRadius() const { return radius; }

void Body::atTime(float t) {
  position.x = velocity.x * t;
  position.y = velocity.y * t;
  position.z = velocity.z * t;
}
