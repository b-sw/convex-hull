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
    explicit Point(int x, int y, int z);
    Point() = default;
    ~Point() = default;

private:
    std::array<int, POINT_COORDS> coords = {};
};