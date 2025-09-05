//
// Created by John Alex on 17/08/2025.
//
#include "../include/vector.h"
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>

Vector::Vector(std::initializer_list<double> values, std::string sys) {
  elements = std::vector(values);
  system = sys;
}

Vector::Vector() {
  elements = {0, 0};
  system = "cartesian";
}

void Vector::toPolar() {
  if (system != "polar") {
    const double x = elements[0];
    const double y = elements[1];
    double r = sqrt(x * x + y * y);
    double theta = atan2(y, x);
    elements = {r, theta};
  }
}

void Vector::toCartesian() {
  if (system != "cartesian") {
    const double r = elements[0];
    const double theta = elements[1];
    double x = r * cos(theta);
    double y = r * sin(theta);
    elements = {x, y};
  }
}

double Vector::norm() const {
  if (system != "polar") {
    double normal = 0;
    for (const double i : elements) {
      normal += i * i;
    }
    normal = sqrt(normal);
    return normal;
  } else {
    return elements[0];
  }
}

std::string Vector::getSystem() { return system; }
void Vector::setSystem(std::string sys) { system = sys; }

std::vector<double> Vector::getCoordinate() { return elements; }

void Vector::setCoordinate(std::initializer_list<double> values) {
  elements = std::vector(values);
}

void Vector::setCoordinate(const std::vector<double> &values) {
  elements = values;
}

void makeCartesian(Vector &c1, Vector &c2) {
  c1.toCartesian();
  c2.toCartesian();
}

Vector operator+(Vector &c1, Vector &c2) {
  std::string system = c1.getSystem();
  makeCartesian(c1, c2);
  std::vector<double> pos1 = c1.getCoordinate();
  std::vector<double> pos2 = c2.getCoordinate();
  std::vector<double> new_pos;
  new_pos.reserve(pos1.size());

  for (int i = 0; i < pos1.size(); i++) {
    new_pos.push_back(pos1[i] + pos2[i]);
  }
  Vector new_coord({new_pos[0], new_pos[1]}, "cartesian");
  if (system == "polar") {
    new_coord.toPolar();
  }
  return new_coord;
}

Vector operator-(Vector &c1, Vector &c2) {
  std::string system = c1.getSystem();
  makeCartesian(c1, c2);
  std::vector<double> pos1 = c1.getCoordinate();
  std::vector<double> pos2 = c2.getCoordinate();
  std::vector<double> new_pos;
  new_pos.reserve(pos1.size());

  for (int i = 0; i < pos1.size(); i++) {
    new_pos.push_back(pos1[i] - pos2[i]);
  }
  Vector new_coord({new_pos[0], new_pos[1]}, "cartesian");
  if (system == "polar") {
    new_coord.toPolar();
  }
  return new_coord;
}

std::ostream &operator<<(std::ostream &os, Vector &c) {
  const std::string system = c.getSystem();
  const std::vector<double> pos = c.getCoordinate();
  if (system == "cartesian") {
    os << "x" << "(";
  } else {
    os << "r" << ")";
  }
  for (int i = 0; i < pos.size() - 1; i++) {
    os << pos[i] << ", ";
  }
  os << pos[pos.size() - 1] << ")";
  return os;
}