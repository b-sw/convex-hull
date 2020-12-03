cmake_minimum_required(VERSION 3.17)
project(convex_hull)

set(CMAKE_CXX_STANDARD 14)

include_directories(hdr)
include_directories(src)

add_executable(convex_hull
        hdr/face.hpp
        hdr/point.hpp
        hdr/edge.hpp
        hdr/test.hpp
        src/point.cpp
        src/face.cpp
        src/edge.cpp
        src/test.cpp
        src/main.cpp)
