//
// Created by John Alex on 18/08/2025.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "body.h"
#include "coordinates.h"

class System {
    double time;
    std::vector<Body> bodies;
    std::vector<Coordinate> forces;

    public:
        System(const std::vector<double> &masses, const std::vector<double> &radii,
               const std::vector<Coordinate> &velocities,
               const std::vector<Coordinate> &coords);

        void calcForces();

        std::vector<Coordinate> getForces();
};

#endif //SYSTEM_H
