//
// Created by John Alex on 04/08/2025.
//

#include "../include/gravity.h"

double forceGravity(const double m1, const double m2, const double r,
                    const double rNorm) {
  if (r == 0) {
    return 0;
  }
  const double _force = (G * m1 * m2 * r) / (pow(rNorm, 3));
  return _force;
}

Vector vectorGravity(Body &b1, Body &b2) {
  const double m1 = b1.getMass();
  const double m2 = b2.getMass();
  Vector disp = b1.getPosition() - b2.getPosition();
  const double rNorm = disp.norm();
  const std::string system = disp.getSystem();

  std::vector<double> forceVector;
  for (const double r : disp.getCoordinate()) {
    double force = forceGravity(m1, m2, r, rNorm);
    forceVector.push_back(force);
  }
  Vector force;

  force.setCoordinate(forceVector);
  force.setSystem(system);
  return force;
}