//
// Created by John Alex on 04/08/2025.
//

#include "../include/gravity.h"

double forceGravity(const Body &b1, const Body &b2) {
  const double m1 = b1.getMass();
  const double m2 = b2.getMass();
  const Vector disp = b1.getPosition() - b2.getPosition();
  std::cout << "Displacement: " << disp << std::endl;
  const double r = disp.norm();
  std::cout << "Disp norm: " << r << std::endl;
  return ((G * m1 * m2) / (r * r));
}

double accelGravity(const double &force, const Body &body) {
  return force / body.getMass();
}
