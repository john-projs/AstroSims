//
// Created by John Alex on 02/08/2025.
//

#ifndef BODY_H
#define BODY_H
#include "../include/vector.h"
#include <iostream>

class Body {
  std::string label;
  double mass;
  double radius;
  Vector acceleration;
  Vector velocity;
  Vector position;

public:
  Body(const std::string &bodyName, double m, double r, Vector &a, Vector &v,
       Vector &p);

  [[nodiscard]] Vector &getAcceleration();
  void setAcceleration(Vector new_accel);

  [[nodiscard]] Vector &getVelocity();
  void setVelocity(Vector new_vel);

  [[nodiscard]] Vector &getPosition();
  void setPosition(Vector new_pos);

  [[nodiscard]] double getMass() const;

  [[nodiscard]] double getRadius() const;
};

std::ostream &operator<<(std::ostream &os, const Body &bd);

#endif // BODY_H
