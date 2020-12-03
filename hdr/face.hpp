/*
*	Name:		face.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include "point.hpp"

#define FACE_POINTS 3

class Face{
public:
    explicit Face(Point pts[FACE_POINTS]);
    Face() = default;
    ~Face() = default;

private:
    std::array<Point, FACE_POINTS> points = {};
};