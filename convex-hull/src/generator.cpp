/*
*	Name:		generator.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "generator.hpp"

std::vector<Point> Generator::generatePoints(int seed, int n) {
    std::mt19937 mt(seed);
    std::normal_distribution<double> dist(MU, VAR);
    std::vector<Point> points;

    for(int i=0; i<n; ++i) {
        double x = dist(mt);
        double y = dist(mt);
        double z = dist(mt);
        auto point = new Point(x, y, z);

        points.push_back(*point);
    }

    return points;
}