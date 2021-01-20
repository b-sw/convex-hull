cmake_minimum_required(VERSION 3.17)
project(convex_hull)

set(CMAKE_CXX_STANDARD 14)
include_directories(convex-hull/lib)
include_directories(convex-hull/src)

add_executable(convex_hull
        convex-hull/lib/face.hpp
        convex-hull/lib/point.hpp
        convex-hull/lib/edge.hpp
        convex-hull/lib/test.hpp
        convex-hull/lib/generator.hpp
        convex-hull/src/point.cpp
        convex-hull/src/face.cpp
        convex-hull/src/edge.cpp
        convex-hull/tests/test.cpp
        convex-hull/src/generator.cpp
        convex-hull/src/main.cpp convex-hull/lib/chull.hpp convex-hull/src/chull.cpp convex-hull/src/preprocessing.cpp convex-hull/lib/preprocessing.hpp convex-hull/src/algorithms.cpp convex-hull/lib/algorithms.hpp convex-hull/src/stopwatch.cpp convex-hull/lib/stopwatch.hpp)
