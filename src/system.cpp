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

Coordinate sumForces(std::vector<Body> &bodies, int body) {
    double f_x = 0;
    double f_y = 0;
    std::string system = bodies[0].getPosition().getSystem();
    for (int j=0; j < bodies.size(); j++) {
        if (j != body) {
            Coordinate gravForce = vectorGravity(bodies[j], bodies[body]);
            f_x += gravForce.getCoordinate()[0];
            f_y += gravForce.getCoordinate()[1];
        }
    }
    Coordinate forceOnBody(f_x, f_y, system);
    return forceOnBody;
}

void System::calcForces() {
    std::vector<Coordinate> new_forces;
    for (int i = 0; i < bodies.size(); i++) {
        Coordinate gravForce = sumForces(bodies, i);
        new_forces.push_back(gravForce);
    }
    forces = new_forces;
}

std::vector<Coordinate> System::getForces() { return forces; }
