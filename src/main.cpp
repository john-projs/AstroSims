#include "../include/body.h"
#include "../include/gravity.h"
#include "../include/utils.h"
#include <iostream>

int main() {
  constexpr Vector vel(0.0, 0.0);

  Vector pos1(0, 0);
  Vector pos2(271812000, 271812000);
  const Body earth(massEarth, radiusEarth, vel, pos1);
  const Body moon(massMoon, radiusMoon, vel, pos2);

  double g = forceGravity(earth, moon);
  double accel = accelGravity(g, moon);
  std::cout << g << std::endl;
  std::cout << accel << std::endl;

  return 0;
};
