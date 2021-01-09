/*
*	Name:		point.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
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

    auto& operator[](int i) const{return this->coords[i];}
    friend bool operator==(const Point& a, const Point& b){
        return a[X] == b[X] && a[Y] == b[Y] && a[Z] == b[Z];
    }

private:
    std::array<double, POINT_COORDS> coords = {};
};