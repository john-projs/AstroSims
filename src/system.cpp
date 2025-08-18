//
// Created by John Alex on 18/08/2025.
//
#include "../include/system.h"
#include "../include/body.h"
#include "../include/gravity.h"

System::System(const std::vector<double> &masses, const std::vector<double> &radii,
               const std::vector<Coordinate> &velocities, const std::vector<Coordinate> &coords) {
    time = 0;
    for (int i = 0; i < masses.size(); i++) {
        Body body(masses[i], radii[i], velocities[i], coords[i]);
        bodies.push_back(body);
    }
}

void System::calcForces() {
    std::vector<double> new_forces;
    for (int i = 0; i < bodies.size() - 1; i++) {
        double gravForce = forceGravity(bodies[i], bodies[i + 1]);
        new_forces.push_back(gravForce);
    }
    new_forces.push_back(new_forces.at(new_forces.size() - 1));
    forces = new_forces;
}

std::vector<double> System::getForces() { return forces; }
