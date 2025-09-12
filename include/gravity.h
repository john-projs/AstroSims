//
// Created by John Alex on 03/08/2025.
//

#ifndef GRAVITY_H
#define GRAVITY_H

#include "../include/body.h"
#include "../include/vector.h"
#include <cmath>

// Defining constants in astronomical units

inline double au = 149597870700;
inline double parsec = 3.0857 * pow(10, 16);

// G defined in km^3 * Solar Mass^-1 * s^-2
inline double G = 1.327124 * pow(10, 11);

// Defined in Solar Masses
inline double massEarth = 3.00274 * pow(10, -6);
inline double massMoon = 3.6940 * pow(10, -8);
inline double massSun = 1.0;

// Defined in km
inline double radiusEarth = 6.378 * pow(10, 6);
inline double radiusSun = 6.9634 * pow(10, 8);
inline double radiusMoon = 1.7374 * pow(10, 6);
inline double earthsunDistance = 1.4960 * pow(10, 8);
inline double aphelion = 1.5210 * pow(10, 8);
inline double perihelion = 1.4710 * pow(10, 8);
// Speed in km
inline double speedAtAphelion = 29.29;
inline double speedAtPerihelion = 30.29;

Vector vectorGravity(Body &b1, Body &b2);

double accelGravity(const double &force, const Body &b2);

#endif // GRAVITY_H
