/*
*	Name:		time.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include <chrono>

#include "algorithms.hpp"

#define TIMES_FILE "..\\convex-hull\\times\\times.data"
//#define WRITE_FILE std::ios::out

class Stopwatch {
public:
    Stopwatch() = default;
    ~Stopwatch() = default;

    auto timeAlgorithm(const std::vector<Point>& points, ConvexHull algorithm(const std::vector<Point>&));

    void timeForN(int n, const std::vector<Point>& points, ConvexHull (*algorithm)(const std::vector<Point>&));

    void write();

private:
//    std::vector<int> times;
};