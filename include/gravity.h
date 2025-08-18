//
// Created by John Alex on 03/08/2025.
//

#ifndef GRAVITY_H
#define GRAVITY_H

#include "../include/body.h"
#include <cmath>

inline double G = 6.67430 * pow(10, -11);
inline double massEarth = 5.9722 * pow(10, 24);
inline double massMoon = 7.346 * pow(10, 22);
inline double radiusEarth = 6.378 * pow(10, 6);
inline double radiusMoon = 1.7374 * pow(10, 6);


double forceGravity(Body &b1, Body &b2);

double accelGravity(const double &force, const Body &b2);

#endif // GRAVITY_H
