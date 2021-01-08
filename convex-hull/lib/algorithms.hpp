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
    ConvexHull naive(std::vector<Point> points);

    ConvexHull giftWrapping(std::vector<Point> points);

    ConvexHull incremental(std::vector<Point> points);

    ConvexHull divideNConquer(std::vector<Point> points);
}