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

#include <unordered_set>

#include "chull.hpp"

#define FOUR 4

namespace algorithms {
    ConvexHull naive(const std::vector<Point>& points);

    ConvexHull giftWrapping(const std::vector<Point>& points);

    ConvexHull incremental(const std::vector<Point>& points);

    ConvexHull divideNConquer(const std::vector<Point>& points);

    bool isVisible(Point p1, Point p2, Point p3, Point pt);
    bool isVisible(Face face, Point point);

    Face firstFace(const std::vector<Point>& points);

    double angleBetweenPlanes(Point edgePoint1, Point edgePoint2, Point point1, Point point2);
}