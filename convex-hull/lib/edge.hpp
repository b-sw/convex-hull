/*
*	Name:		edge.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include "point.hpp"

#define EDGE_POINTS 2

class Edge{
public:
    explicit Edge(const int points[EDGE_POINTS]);
    Edge() = default;
    ~Edge() = default;

    auto& operator[](int i) {return this->points[i];}

private:
    std::array<int, EDGE_POINTS> points = {};
};