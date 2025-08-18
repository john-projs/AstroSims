#include "../include/body.h"
#include "../include/gravity.h"
#include "../include/utils.h"
#include "../include/coordinates.h"
#include "../include/system.h"
#include <iostream>

int main() {
  std::vector<double> masses = {1, 10, 100, 1000};
  std::vector<double> radii = {1, 1, 1, 1};
  Coordinate v1(0, 0, "cartesian");
  Coordinate v2(0, 0, "cartesian");
  Coordinate v3(0, 0, "cartesian");
  Coordinate v4(0, 0, "cartesian");
  std::vector velocities = {v1, v2, v3, v4};
  Coordinate c1(0, 0, "cartesian");
  Coordinate c2(100, 200, "cartesian");
  Coordinate c3(1000, 5000, "cartesian");
  Coordinate c4(10000, 9000, "cartesian");
  std::vector positions = {c1, c2, c3, c4};
  System system(masses, radii, velocities, positions);

  system.calcForces();
  std::vector<Coordinate> forces = system.getForces();

  for (auto force: forces) {
    std::cout << force << ", " << std::endl;
  }
  return 0;
};
