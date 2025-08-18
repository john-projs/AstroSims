//
// Created by John Alex on 17/08/2025.
//
#include "../include/coordinates.h"
#include <cmath>
#include <vector>
#include <iostream>

Coordinate::Coordinate(const double c1, const double c2, const std::string &s) {
    coordinate = std::vector<double>(2) = {c1, c2};
    system = s;
}

Coordinate::Coordinate() {
    coordinate = {0, 0};
    system = "cartesian";
}


void Coordinate::toPolar() {
    if (system != "polar") {
        const double x = coordinate[0];
        const double y = coordinate[1];
        double r = sqrt(x * x + y * y);
        double theta = atan2(y, x);
        coordinate = {r, theta};
    }
}

void Coordinate::toCartesian() {
    if (system != "cartesian") {
        const double r = coordinate[0];
        const double theta = coordinate[1];
        double x = r * cos(theta);
        double y = r * sin(theta);
        coordinate = {x, y};
    }
}

double Coordinate::norm() const {
    if (system != "polar") {
        double normal = 0;
        for (const double i: coordinate) {
            normal += i * i;
        }
        normal = sqrt(normal);
        return normal;
    } else {
        return coordinate[0];
    }
}

std::string Coordinate::getSystem() { return system; }
std::vector<double> Coordinate::getCoordinate() { return coordinate; }

void makeCartesian(Coordinate &c1, Coordinate &c2) {
    c1.toCartesian();
    c2.toCartesian();
}

Coordinate operator+(Coordinate &c1, Coordinate &c2) {
    std::string system = c1.getSystem();
    makeCartesian(c1, c2);
    std::vector<double> pos1 = c1.getCoordinate();
    std::vector<double> pos2 = c2.getCoordinate();
    std::vector<double> new_pos;
    new_pos.reserve(pos1.size());

    for (int i = 0; i < pos1.size(); i++) {
        new_pos.push_back(pos1[i] + pos2[i]);
    }
    Coordinate new_coord(new_pos[0], new_pos[1], "cartesian");
    if (system == "polar") {
        new_coord.toPolar();
    }
    return new_coord;
}

Coordinate operator-(Coordinate &c1, Coordinate &c2) {
    std::string system = c1.getSystem();
    makeCartesian(c1, c2);
    std::vector<double> pos1 = c1.getCoordinate();
    std::vector<double> pos2 = c2.getCoordinate();
    std::vector<double> new_pos;
    new_pos.reserve(pos1.size());

    for (int i = 0; i < pos1.size(); i++) {
        new_pos.push_back(pos1[i] - pos2[i]);
    }
    Coordinate new_coord(new_pos[0], new_pos[1], "cartesian");
    if (system == "polar") {
        new_coord.toPolar();
    }
    return new_coord;
}


std::ostream &operator<<(std::ostream &os, Coordinate &c) {
    const std::string system = c.getSystem();
    const std::vector<double> pos = c.getCoordinate();
    os << system << "(";
    for (int i = 0; i < pos.size() - 1; i++) {
        os << pos[i] << ", ";
    }
    os << pos[pos.size() - 1] << ")";
    return os;
}
