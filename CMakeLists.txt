cmake_minimum_required(VERSION 3.31)
project(Astro)

set(CMAKE_CXX_STANDARD 20)

add_executable(Astro src/main.cpp
        include/body.h
        include/utils.h
        include/gravity.h
        src/body.cpp
        src/gravity.cpp
)
