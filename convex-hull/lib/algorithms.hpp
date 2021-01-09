/*
*	Name:		algorithms.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include <vector>

#include "chull.hpp"

namespace algorithms {
    ConvexHull naive(const std::vector<Point>& points);

    ConvexHull giftWrapping(const std::vector<Point> points);

    ConvexHull incremental(const std::vector<Point> points);

    ConvexHull divideNConquer(const std::vector<Point> points);

    bool isOutside(Point p1, Point p2, Point p3, Point tested);
}