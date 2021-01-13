/*
*	Name:		edge.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "edge.hpp"

Edge::Edge(Point point1, Point point2){
    this->points[0] = point1;
    this->points[1] = point2;
}
