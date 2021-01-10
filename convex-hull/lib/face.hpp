/*
*	Name:		face.hpp
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
#include "edge.hpp"

#define FACE_POINTS 3

class Face{
public:
    explicit Face(Point point1, Point point2, Point point3);
    Face() = default;
    ~Face() = default;

    auto& operator[](int i) const {return this->points[i];}

    std::vector<Edge> getEdges();

private:
    std::array<Point, FACE_POINTS> points = {};
};