/*
*	Name:		chull.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include "face.hpp"
#include <fstream>
#include <iostream>

#define POINTS_FILE "points2.data"
#define VERTICES_FILE "vertices2.data"
#define FACES_FILE "facets2.data"
#define SEPARATOR ';'
#define WRITE_FILE std::ios::out

class ConvexHull{
public:
    explicit ConvexHull(Point* points, int* vertices, Face* faces);
    ConvexHull() = default;
    ~ConvexHull() = default;

    void save();

    inline Point* getPoints()  {return this->points;}
    inline int* getVertices()  {return this->vertices;}
    inline Face* getFaces()    {return this->faces;}
private:
    Point* points;
    int* vertices;
    Face* faces;
};