#include "../include/body.h"
#include "../include/gravity.h"
#include "../include/system.h"
#include "../include/utils.h"
#include <iostream>

int main() {
  std::vector<double> masses = {massSun, massEarth};
  std::vector<double> radii = {radiusSun, radiusEarth};

  Vector v1({0, 0}, "cartesian");
  Vector v2({0, 0}, "cartesian");
  std::vector velocities = {v1, v2};

  Vector a1({0, 0}, "cartesian");
  Vector a2({0, 0}, "cartesian");
  std::vector acceleration = {a1, a2};

  Vector c1({0, 0}, "cartesian");
  Vector c2({0, earthsunDistance}, "cartesian");
  std::vector positions = {c1, c2};

  std::vector<std::string> names = {"sun", "earth"};

  System system(names, masses, radii, acceleration, velocities, positions);


  for (int i = 0; i < 100; i++) {
    std::cout << "Tick: " << i << std::endl;
    std::vector<Vector> coords = system.getCoordinates();
    Vector earth = coords[1];
    std::cout << earth << std::endl;
    system.forwardTick();
  }

  return 0;
};
