//
// Created by John Alex on 02/08/2025.
//

#ifndef UTILS_H
#define UTILS_H
#include <sstream>
#include <string>

template <typename T> std::string to_string(const T &value) {
  std::ostringstream ss;
  ss << value;
  return ss.str();
}

template <typename T>
std::string join(const std::string &delimiter, const std::vector<T> &args) {
  std::string new_string = to_string(args[0]);
  for (int i = 1; i < args.size(); i++) {
    new_string += delimiter + to_string(args[i]);
  }
  return new_string;
}

template <typename T>
std::vector<T> add(std::vector<T> &v1, std::vector<T> &v2) {
  v1.insert(v1.end(), v2.begin(), v2.end());
  return v1;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v1) {
  os << "[";
  for (int i = 0; i < v1.size() - 1; i++) {
    os << v1[i] << ", ";
  }
  os << v1[v1.size() - 1] << "]";
  return os;
};

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, std::unordered_map<K, V> &umap) {
  os << "{";
  for (auto entry = umap.begin(); entry != umap.end();) {
    K key = entry->first;
    V value = entry->second;
    // Pass key to os
    os << "\"" << key << "\"" << ": ";
    // Pass value to os
    if (++entry == umap.end()) {
      os << value;
    } else {
      os << value << ",";
    }
  }
  os << "}";
  return os;
}
#endif // UTILS_H
