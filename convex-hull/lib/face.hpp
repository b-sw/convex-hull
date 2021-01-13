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
    friend bool operator==(const Face& a, const Face& b){
        return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
               || (a[0] == b[0] && a[1] == b[2] && a[2] == b[1])
               || (a[0] == b[1] && a[1] == b[0] && a[2] == b[2])
               || (a[0] == b[1] && a[1] == b[2] && a[2] == b[0])
               || (a[0] == b[2] && a[1] == b[0] && a[2] == b[1])
               || (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]);
    }

    std::vector<Edge> getEdges();

private:
    std::array<Point, FACE_POINTS> points = {};
};