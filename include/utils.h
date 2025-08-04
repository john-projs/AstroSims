//
// Created by John Alex on 02/08/2025.
//

#ifndef UTILS_H
#define UTILS_H
#include <sstream>
#include <string>

template <typename T>
std::string to_string( const T& value )
{
    std::ostringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
inline std::string join(const std::string& delimiter, const std::vector<T>& args) {
    std::string new_string = to_string(args[0]);
    for (int i = 1; i < args.size(); i++) {
        new_string += delimiter + to_string(args[i]);
    }
    return new_string;
}

#endif //UTILS_H
