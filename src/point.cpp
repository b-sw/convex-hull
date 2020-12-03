/*
*	Name:		point.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "point.hpp"

Point::Point(int x, int y, int z){
    this->coords[X] = x;
    this->coords[Y] = y;
    this->coords[Z] = z;
}
