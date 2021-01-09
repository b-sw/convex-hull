/*
*	Name:		face.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "face.hpp"

Face::Face(Point point1, Point point2, Point point3) {
    this->points[0] = point1;
    this->points[1] = point2;
    this->points[2] = point3;
}
