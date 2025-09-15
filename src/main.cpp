#include "../include/body.h"
#include "../include/datastore.h"
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

    for (int j = 0; j < vel.size(); j++) {
      const double v = vel[j];
      if (j < vel.size() - 1)
        writer << v << ",";
      else {
        writer << v;
      }
    }
    writer << std::endl;
  }
}

void runSimulation(System &system, DataStore &data, int ticks) {
  for (int i = 0; i < ticks; i++) {
    system.forwardTick();
    data.updateSystemState(system);
  }
  std::fstream writer = data.openFile("../output/data.json");
  data.writeToFile(writer);
}

int main() {
  int ticks = 50000;
  // file pointer
  std::fstream writer;
  writer.open("../output/data.csv", std::ios::out);

  std::vector<double> masses = {massSun, massEarth};
  std::vector<double> radii = {radiusSun, radiusEarth};

  Vector v1({0, 0, 0}, "cartesian");
  Vector v2({0, 13, 0}, "cartesian");
  Vector v3({5, -5, 0}, "cartesian");
  std::vector velocities = {v1, v2};

  Vector a1({0, 0, 0}, "cartesian");
  Vector a2({-0.00006, -0.00006, 0}, "cartesian");
  Vector a3({0, 0, 0}, "cartesian");
  std::vector acceleration = {a1, a2};

  Vector c1({0, 0, 0}, "cartesian");
  Vector c2({aphelion, 0, 0}, "cartesian");
  Vector c3({0, 3 * au, 0}, "cartesian");
  std::vector positions = {c1, c2};

  std::vector<std::string> names = {"sun", "earth"};

  System earthSun(names, masses, radii, acceleration, velocities, positions);
  earthSun.setTickRate(100000);
  DataStore data(earthSun);

  runSimulation(earthSun, data, ticks);

  return 0;
};
