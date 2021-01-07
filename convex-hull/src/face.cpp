/*
*	Name:		face.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "face.hpp"

Face::Face(const int points[FACE_POINTS]){
    for(int i = 0; i < FACE_POINTS; ++i){
        this->points[i] = points[i];
    }
}