//
// Created by John Alex on 05/08/2025.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>

class Vector {
  std::vector<double> elements;
  std::string system;

public:
  Vector(std::initializer_list<double> values, std::string sys);

  Vector(const std::vector<double> &values, const std::string &sys);

  Vector();

  void toPolar();

  void toCartesian();

  [[nodiscard]] double norm() const;

  std::string getSystem();
  void setSystem(std::string sys);

  std::vector<double> getCoordinate();

  void setCoordinate(std::initializer_list<double> values);
  void setCoordinate(const std::vector<double> &values);
};

void makeCartesian(Vector &c1, Vector &c2);

Vector operator+(Vector &c1, Vector &c2);

Vector operator-(Vector &c1, Vector &c2);

template <typename T> Vector operator*(Vector &c1, T &multiplier) {
  static_assert(std::is_arithmetic_v<T>, "An arithmetic type is required");
  std::vector<double> new_values;
  for (double val : c1.getCoordinate()) {
    new_values.push_back(val * multiplier);
  }
  c1.setCoordinate(new_values);
  return c1;
}

template <typename T> Vector operator/(Vector &c1, T divisor) {
  static_assert(std::is_arithmetic_v<T>, "An arithmetic type is required");
  std::vector<double> new_values;
  for (double val : c1.getCoordinate()) {
    double new_val = val / divisor;
    new_values.push_back(new_val);
  }
  c1.setCoordinate(new_values);
  return c1;
}

std::ostream &operator<<(std::ostream &os, Vector &c);

#endif // VECTOR_H
