/*
*	Name:		edge.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include "point.hpp"

#define EDGE_POINTS 2

class Edge{
public:
    explicit Edge(Point pts[EDGE_POINTS]);
    Edge() = default;
    ~Edge() = default;

private:
    std::array<Point, EDGE_POINTS> points = {};
};