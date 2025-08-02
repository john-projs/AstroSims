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

#endif //UTILS_H
