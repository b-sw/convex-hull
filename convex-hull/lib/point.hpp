/*
*	Name:		point.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include <array>

#define POINT_COORDS 3
#define X 0
#define Y 1
#define Z 2

class Point{
public:
    explicit Point(double x, double y, double z);
    Point() = default;
    ~Point() = default;

    auto& operator[](int i) {return this->coords[i];}

    inline double getX() { return coords[X]; }
    inline double getY() { return coords[Y]; }
    inline double getZ() { return coords[Z]; }

private:
    std::array<double, POINT_COORDS> coords = {};
};