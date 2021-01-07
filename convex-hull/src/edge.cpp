/*
*	Name:		edge.cpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "edge.hpp"

Edge::Edge(const int points[EDGE_POINTS]){
    for(int i = 0; i < EDGE_POINTS; ++i){
        this->points[i] = points[i];
    }
}
