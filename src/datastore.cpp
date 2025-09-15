//
// Created by John Alex on 13/09/2025.
//
#include "../include/datastore.h"
#include "../include/system.h"
#include "../include/utils.h"

#include <fstream>
#include <string>
#include <unordered_map>

DataStore::DataStore(System &sys) {
  std::vector<std::string> labels = sys.getLabels();
  for (int i = 0; i < labels.size(); i++) {
    Body body = sys.getBody(i);
    std::vector bodyMass = {body.getMass()};
    std::vector bodyRadius = {body.getRadius()};
    std::vector bodyMetrics = {bodyMass, bodyRadius};
    data[labels[i]]["body"] = bodyMetrics;
    data[labels[i]]["position"] = sys.unpackVector(sys.getCoordinates(), i);
    data[labels[i]]["velocity"] = sys.unpackVector(sys.getVelocities(), i);
    data[labels[i]]["acceleration"] =
        sys.unpackVector(sys.getAccelerations(), i);
    data[labels[i]]["forces"] = sys.unpackVector(sys.getForces(), i);
  }
}

std::unordered_map<
    std::string,
    std::unordered_map<std::string, std::vector<std::vector<double>>>>
DataStore::getData() {
  return data;
}

void DataStore::updateSystemState(System &sys) {
  std::vector<std::string> labels = sys.getLabels();
  for (int i = 0; i < labels.size(); i++) {
    std::vector<std::vector<double>> new_pos =
        sys.unpackVector(sys.getCoordinates(), i);
    std::vector<std::vector<double>> new_vel =
        sys.unpackVector(sys.getVelocities(), i);
    std::vector<std::vector<double>> new_accel =
        sys.unpackVector(sys.getAccelerations(), i);
    std::vector<std::vector<double>> new_force =
        sys.unpackVector(sys.getForces(), i);
    updateEntry(labels[i], "position", new_pos);
    updateEntry(labels[i], "velocity", new_vel);
    updateEntry(labels[i], "acceleration", new_accel);
    updateEntry(labels[i], "forces", new_force);
  }
}

void DataStore::updateEntry(std::string label, std::string key,
                            std::vector<std::vector<double>> new_val) {
  data[label][key].insert(data[label][key].end(), new_val.begin(),
                          new_val.end());
}

std::fstream DataStore::openFile(const std::string &filename) {
  // file pointer
  std::fstream writer;
  writer.open(filename, std::ios::out);
  return writer;
}

void DataStore::writeToFile(std::fstream &writer) {
  writer << data << std::endl;
}
