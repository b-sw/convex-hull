/*
*	Name:		face.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "../lib/face.hpp"

Face::Face(Point pts[FACE_POINTS]){
    for(int i = 0; i < FACE_POINTS; ++i){
        this->points[i] = pts[i];
    }
}