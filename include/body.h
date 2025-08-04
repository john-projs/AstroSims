//
// Created by John Alex on 02/08/2025.
//

#ifndef BODY_H
#define BODY_H
#include<string>
#include <iostream>
#include "utils.h"

struct Velocity {
    double x;
    double y;
    double z;
};

struct Position {
    double x;
    double y;
    double z;
};

inline std::ostream& operator<<(std::ostream& os, const Velocity& vel)
{
    const std::vector<double> args = {vel.x, vel.y, vel.z};
    const std::string repr = "v⃗(" + join(", ", args) + ")";
    os << repr;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Position& pos)
{
    const std::vector<double> args = {pos.x, pos.y, pos.z};
    const std::string repr = "x⃗("+join(", ", args) + ")";
    os << repr;
    return os;
}


class Body {
    public:
    double mass;
    double radius;
    Velocity velocity{};
    Position position{};

    Body(const double m, const double r, const Velocity &v, const Position &p) {
        mass = m;
        radius = r;
        velocity = v;
        position = p;
    }

    void atTime(const double t) {
        position.x = velocity.x * t;
        position.y = velocity.y * t;
        position.z = velocity.z * t;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Body& bd)
{
    const std::string velPos = to_string(bd.velocity) + " " + to_string(bd.position);
    os << std::format("Body(m: {}, r: {}, ", bd.mass, bd.radius) << velPos << ")";
    return os;
}

#endif //BODY_H
