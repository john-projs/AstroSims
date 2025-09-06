//
// Created by John Alex on 04/08/2025.
//

#include "../include/gravity.h"

double forceGravity(double m1, double m2, double r) {
  if (r == 0) {
    return 0;
  }
  return (G * m1 * m2) / (r * r);
}

Vector vectorGravity(Body &b1, Body &b2) {
  const double m1 = b1.getMass();
  const double m2 = b2.getMass();
  Vector disp = b2.getPosition() - b1.getPosition();
  const std::string system = disp.getSystem();

  std::vector<double> forceVector;
  for (const double r : disp.getCoordinate()) {
    double force = forceGravity(m1, m2, r);
    if (r < 0) {
      force = -1 * force;
    }
    forceVector.push_back(force);
  }
  Vector force;

  force.setCoordinate(forceVector);
  force.setSystem(system);
  return force;
}