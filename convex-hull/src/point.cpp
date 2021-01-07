/*
*	Name:		point.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "point.hpp"

Point::Point(double x, double y, double z){
    this->coords[X] = x;
    this->coords[Y] = y;
    this->coords[Z] = z;
}