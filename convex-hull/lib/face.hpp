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

#include "point.hpp"
#define FACE_POINTS 3

class Face{
public:
    explicit Face(const int points[FACE_POINTS]);
    Face() = default;
    ~Face() = default;

    auto& operator[](int i) const {return this->points[i];}

private:
    std::array<int, FACE_POINTS> points = {};
};