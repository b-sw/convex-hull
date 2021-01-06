/*
*	Name:		point.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "../lib/point.hpp"

Point::Point(double x, double y, double z){
    this->coords[X] = x;
    this->coords[Y] = y;
    this->coords[Z] = z;
}
