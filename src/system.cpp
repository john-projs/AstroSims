//
// Created by John Alex on 18/08/2025.
//
#include "../include/system.h"
#include "../include/body.h"
#include "../include/gravity.h"

System::System(const std::vector<double> &masses,
               const std::vector<double> &radii,
               const std::vector<Vector> &velocities,
               const std::vector<Vector> &coords) {
  time = 0;
  for (int i = 0; i < masses.size(); i++) {
    Body body(masses[i], radii[i], velocities[i], coords[i]);
    bodies.push_back(body);
  }
}

Vector sumForces(std::vector<Body> &bodies, int body) {

  std::vector<double> template_vector = bodies[0].getPosition().getCoordinate();
  std::vector<double> forceVector(template_vector.size(), 0);

  std::string system = bodies[0].getPosition().getSystem();
  for (int j = 0; j < bodies.size(); j++) {
    if (j != body) {
      Vector gravForce = vectorGravity(bodies[j], bodies[body]);
      std::vector<double> gravVector = gravForce.getCoordinate();
      for (int i = 0; i < gravVector.size(); i++) {
        forceVector[i] += gravVector[i];
      }
    }
  }
  Vector forceOnBody;
  forceOnBody.setCoordinate(forceVector);
  forceOnBody.setSystem(system);
  return forceOnBody;
}

void System::updateForces() {
  std::vector<Vector> new_forces;
  for (int i = 0; i < bodies.size(); i++) {
    Vector gravForce = sumForces(bodies, i);
    new_forces.push_back(gravForce);
  }
  forces = new_forces;
}

std::vector<Vector> System::getForces() { return forces; }

void System::updateCoordinates() {
  for (auto currBody : bodies) {
    Vector bodyVelocity = currBody.getVelocity();
    Vector currPosition = currBody.getPosition();
    Vector displacement = bodyVelocity * tick_rate;
    Vector newPosition = currPosition + displacement;
  }
}
