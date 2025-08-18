#include "../include/body.h"
#include "../include/gravity.h"
#include "../include/utils.h"
#include "../include/coordinates.h"
#include "../include/system.h"
#include <iostream>

int main() {
  std::vector<double> masses = {1, 10, 1, 100};
  std::vector<double> radii = {1, 1, 1, 1};
  Coordinate v1(0, 0, "polar");
  Coordinate v2(0, 0, "polar");
  Coordinate v3(0, 0, "polar");
  Coordinate v4(0, 0, "polar");
  std::vector velocities = {v1, v2, v3, v4};
  Coordinate c1(0, 0, "polar");
  Coordinate c2(100, 0, "polar");
  Coordinate c3(1000, 0, "polar");
  Coordinate c4(10000, 0, "polar");
  std::vector positions = {c1, c2, c3, c4};
  System system(masses, radii, velocities, positions);

  system.calcForces();
  std::vector<double> forces = system.getForces();

  for (auto force: forces) {
    std::cout << force << ", " << std::endl;
  }
  return 0;
};
