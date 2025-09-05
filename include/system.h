//
// Created by John Alex on 18/08/2025.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include "body.h"
#include "vector.h"
#include <vector>

class System {
  int tick_rate;
  double time;
  std::vector<Body> bodies;
  std::vector<Vector> forces;

public:
  System(const std::vector<double> &masses, const std::vector<double> &radii,
         const std::vector<Vector> &velocities,
         const std::vector<Vector> &coords);

  void updateCoordinates();
  void updateVelocity();
  void updateForces();

  std::vector<Vector> getCoordinates();
  std::vector<Vector> getForces();
  std::vector<Vector> getVelocities();
};

#endif // SYSTEM_H
