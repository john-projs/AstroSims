//
// Created by John Alex on 02/08/2025.
//

#ifndef BODY_H
#define BODY_H
#include <iostream>

struct Vector {
    double x = 0;
    double y = 0;
    double z = 0;

    [[nodiscard]] double norm() const { return sqrt(x * x + y * y + z * z); }
};

std::ostream &operator<<(std::ostream &os, const Vector &vel);

Vector operator-(const Vector &vec1, const Vector &vec2);

Vector operator+(const Vector &vec1, const Vector &vec2);

class Body {
    double mass;
    double radius;
    Vector velocity{};
    Vector position{};

    public:
        Body(double m, double r, const Vector &v, const Vector &p);

        [[nodiscard]] Vector getVelocity() const;

        [[nodiscard]] Vector getPosition() const;

        [[nodiscard]] double getMass() const;

        [[nodiscard]] double getRadius() const;

        void atTime(float t);
};

std::ostream &operator<<(std::ostream &os, const Body &bd);

#endif // BODY_H
