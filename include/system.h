//
// Created by John Alex on 18/08/2025.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include "body.h"
#include "vector.h"
#include <vector>

class System {
  int tick_rate = 86400;
  int tick = 0;
  std::vector<Body> bodies;
  std::vector<Vector> forces;

public:
  System(const std::vector<std::string> &names,
         const std::vector<double> &masses, const std::vector<double> &radii,
         std::vector<Vector> &acceleration, std::vector<Vector> &velocities,
         std::vector<Vector> &coords);

  void updateCoordinates();
  void updateVelocity();
  void updateForces();
  void updateAcceleration();
  void setTickRate(int new_rate);

  void forwardTick();

  std::vector<Vector> getCoordinates();
  std::vector<Vector> getForces();
  std::vector<Vector> getVelocities();
  std::vector<Vector> getAccelerations();
  std::vector<std::string> getLabels();
  Body getBody(int index);

  std::vector<std::vector<double>> unpackVector(std::vector<Vector> vec,
                                                int index);
};

#endif // SYSTEM_H
