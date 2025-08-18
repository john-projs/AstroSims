//
// Created by John Alex on 05/08/2025.
//

#ifndef COORDINATES_H
#define COORDINATES_H
#include <vector>
#include <iostream>

class Coordinate {
    std::vector<double> coordinate;
    std::string system;

    public:
        Coordinate(double c1, double c2, const std::string &s);

        Coordinate();

        void toPolar();

        void toCartesian();

        [[nodiscard]] double norm() const;

        std::string getSystem();

        std::vector<double> getCoordinate();
};

void makeCartesian(Coordinate &c1, Coordinate &c2);

Coordinate operator+(Coordinate &c1, Coordinate &c2);

Coordinate operator-(Coordinate &c1, Coordinate &c2);

std::ostream &operator<<(std::ostream &os, Coordinate &c);

#endif //COORDINATES_H
