/*
*	Name:		preprocessing.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include <vector>

#include "point.hpp"

namespace preprocessing{
    std::vector<Point> preprocess(const std::vector<Point>& inputPoints, double d);
    double maxCoord(const std::vector<Point>& points, int dim);
    double minCoord(const std::vector<Point>& points, int dim);
}