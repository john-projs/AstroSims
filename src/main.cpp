#include "../include/body.h"
#include "../include/gravity.h"
#include "../include/system.h"
#include "../include/utils.h"
#include <fstream>
#include <iostream>

void writeData(int tick, std::vector<std::string> &labels,
               std::vector<Vector> &coords, std::vector<Vector> &vels,
               std::fstream &writer) {

  for (int i = 0; i < coords.size(); i++) {
    writer << tick << ",";
    writer << labels[i] << ",";
    std::vector<double> coord = coords[i].getCoordinate();
    std::vector<double> vel = vels[i].getCoordinate();
    for (const double c : coord) {
      writer << c << ",";
    }
    for (int i = 0; i < vel.size(); i++) {
      const double v = vel[i];
      if (i < vel.size() - 1)
        writer << v << ",";
      else {
        writer << v;
      }
    }
    writer << std::endl;
  }
}

void runSimulation(System &system, std::fstream &writer) {
  writer << "tick,body,x_pos,y_pos,z_pos,x_vel,y_vel,z_vel" << std::endl;
  std::vector<std::string> labels = system.getLabels();
  for (int i = 0; i < 2000; i++) {
    std::vector<Vector> coords = system.getCoordinates();
    std::vector<Vector> vel = system.getVelocities();
    writeData(i, labels, coords, vel, writer);
    system.forwardTick();
  }
  writer.close();
}

int main() {
  // file pointer
  std::fstream writer;
  writer.open("../output/data.csv", std::ios::out);

  std::vector<double> masses = {massSun, massEarth};
  std::vector<double> radii = {radiusSun, radiusEarth};

  Vector v1({0, 0, 0}, "cartesian");
  Vector v2({0, speedAtAphelion, 0}, "cartesian");
  std::vector velocities = {v1, v2};

  Vector a1({0, 0, 0}, "cartesian");
  Vector a2({0, -0.000006, 0}, "cartesian");
  std::vector acceleration = {a1, a2};

  Vector c1({0, 0, 0}, "cartesian");
  Vector c2({aphelion, 0, 0}, "cartesian");
  std::vector positions = {c1, c2};

  std::vector<std::string> names = {"sun", "earth"};

  System earthSun(names, masses, radii, acceleration, velocities, positions);

  runSimulation(earthSun, writer);

  return 0;
};
