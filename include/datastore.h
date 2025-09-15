//
// Created by John Alex on 13/09/2025.
//

#ifndef DATASTORE_H
#define DATASTORE_H
#include "body.h"
#include "system.h"
#include "utils.h"
#include <string>
#include <unordered_map>

class DataStore {
private:
  std::unordered_map<
      std::string,
      std::unordered_map<std::string, std::vector<std::vector<double>>>>
      data;

public:
  DataStore(System &sys);
  std::unordered_map<
      std::string,
      std::unordered_map<std::string, std::vector<std::vector<double>>>>
  getData();
  void updateSystemState(System &sys);
  void updateEntry(std::string label, std::string key,
                   std::vector<std::vector<double>> new_val);
  static std::fstream openFile(const std::string &filename);
  void writeToFile(std::fstream &writer);
};
#endif // DATASTORE_H
