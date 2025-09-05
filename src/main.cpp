#include "../include/body.h"
#include "../include/gravity.h"
#include "../include/system.h"
#include "../include/utils.h"
#include "../include/vector.h"
#include <iostream>

int main() {
  std::vector<double> masses = {1, 10, 100, 1000};
  std::vector<double> radii = {1, 1, 1, 1};
  Vector v1({0, 0}, "cartesian");
  Vector v2({0, 0}, "cartesian");
  Vector v3({0, 0}, "cartesian");
  Vector v4({0, 0}, "cartesian");
  std::vector velocities = {v1, v2, v3, v4};
  Vector c1({0, 0}, "cartesian");
  Vector c2({100, 200}, "cartesian");
  Vector c3({1000, 5000}, "cartesian");
  Vector c4({10000, 9000}, "cartesian");
  std::vector positions = {c1, c2, c3, c4};
  System system(masses, radii, velocities, positions);

  system.updateForces();
  std::vector<Vector> forces = system.getForces();

  for (auto force : forces) {
    std::cout << force << ", " << std::endl;
  }
  return 0;
};
