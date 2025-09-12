//
// Created by John Alex on 18/08/2025.
//
#include "../include/system.h"
#include "../include/body.h"
#include "../include/gravity.h"

System::System(const std::vector<std::string> &names,
               const std::vector<double> &masses,
               const std::vector<double> &radii,
               std::vector<Vector> &acceleration,
               std::vector<Vector> &velocities, std::vector<Vector> &coords) {
  for (int i = 0; i < masses.size(); i++) {
    Body body(names[i], masses[i], radii[i], acceleration[i], velocities[i],
              coords[i]);
    bodies.push_back(body);
  }
}

Vector sumForces(std::vector<Body> &bodies, int body) {

  std::vector<double> template_vector = bodies[0].getPosition().getCoordinate();
  std::vector<double> forceVector(template_vector.size(), 0);

  std::string system = bodies[0].getPosition().getSystem();

  for (int j = 0; j < bodies.size(); j++) {
    if (j != body) {
      Body currBody = bodies[j];
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

void System::updateCoordinates() {
  for (int i = 0; i < bodies.size(); i++) {
    Vector velocityOfBody = bodies[i].getVelocity();
    Vector displacement = velocityOfBody * tick_rate;
    Vector currPosition = bodies[i].getPosition();
    bodies[i].setPosition(currPosition + displacement);
  }
}

void System::updateVelocity() {
  for (int i = 0; i < bodies.size(); i++) {
    Vector velocityOfBody = bodies[i].getVelocity();
    Vector velocityDelta = bodies[i].getAcceleration() * tick_rate;
    bodies[i].setVelocity(velocityOfBody + velocityDelta);
  }
}

void System::updateForces() {
  std::vector<Vector> new_forces;
  for (int i = 0; i < bodies.size(); i++) {
    Vector gravForce = sumForces(bodies, i);
    new_forces.push_back(gravForce);
  }
  forces = new_forces;
}

void System::updateAcceleration() {
  for (int i = 0; i < bodies.size(); i++) {
    double inv_mass = 1 / bodies[i].getMass();
    Vector accelOnBody = forces[i] * inv_mass;
    bodies[i].setAcceleration(accelOnBody);
  }
}

std::vector<Vector> System::getForces() { return forces; }

std::vector<Vector> System::getCoordinates() {
  std::vector<Vector> coords;
  for (auto &body : bodies) {
    coords.push_back(body.getPosition());
  }
  return coords;
}

std::vector<Vector> System::getVelocities() {
  std::vector<Vector> velocities;
  for (auto &body : bodies) {
    velocities.push_back(body.getVelocity());
  }
  return velocities;
}

std::vector<std::string> System::getLabels() {
  std::vector<std::string> labels;
  for (auto &body : bodies) {
    labels.push_back(body.getLabel());
  }
  return labels;
}

void System::forwardTick() {
  updateForces();
  updateAcceleration();
  updateVelocity();
  updateCoordinates();
  tick++;
}