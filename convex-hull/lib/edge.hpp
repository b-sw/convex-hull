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
    explicit Edge(Point point1, Point point2);
    Edge() = default;
    ~Edge() = default;

    auto& operator[](int i) const{return this->points[i];}
    friend bool operator==(const Edge& a, const Edge& b){
        return (a[0] == b[0] && a[1] == b[1]) || (a[0] == b[1] && a[1] == b[0]);
    }

private:
    std::array<Point, EDGE_POINTS> points = {};
};