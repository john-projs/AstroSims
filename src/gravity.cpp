//
// Created by John Alex on 04/08/2025.
//

#include "../include/gravity.h"

double forceGravity(Body &b1, Body &b2) {
  const double m1 = b1.getMass();
  const double m2 = b2.getMass();
  const Coordinate disp = b1.getPosition() - b2.getPosition();
  const double r = disp.norm();
  return (G * m1 * m2) / (r * r);
}

double accelGravity(const double &force, const Body &body) {
  return force / body.getMass();
}
