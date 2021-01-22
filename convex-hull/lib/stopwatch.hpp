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
#include <map>
#include <utility>

#include "algorithms.hpp"
#include "generator.hpp"
#include "preprocessing.hpp"


#define TIMES_FILE "../convex-hull/times/times.data"
#define WRITE_FILE std::ios::out
#define SEPARATOR ';'

class Stopwatch {
public:
    Stopwatch() = default;
    ~Stopwatch() = default;

    auto timeAlgorithm(const std::vector<Point>& points, ConvexHull algorithm(const std::vector<Point>&));

    int timeAverageNRuns(int runs, const std::vector<Point>& points, ConvexHull (*algorithm)(const std::vector<Point>&));

    void examineAlgorithm(int points, int seed, double precision, int problems, int step, int runs, ConvexHull (*algorithm)(const std::vector<Point>&));

    void save();

private:
    std::map<int,std::pair<int,double>> scores;

    std::vector<int> keys;
};