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

#define POINTS_FILE "..\\convex-hull\\visuals\\points2.data"
#define VERTICES_FILE "..\\convex-hull\\visuals\\vertices2.data"
#define FACES_FILE "..\\convex-hull\\visuals\\faces2.data"
#define SEPARATOR ';'
#define WRITE_FILE std::ios::out
#define SIZES 3
#define POINTS_IDX 0
#define VERTICES_IDX 1
#define FACES_IDX 2

class ConvexHull{
public:
    explicit ConvexHull(Point* points, int* vertices, Face* faces, const int sizes[SIZES]);
    ConvexHull() = default;
    ~ConvexHull() = default;

    void save();

private:
    Point* points{};
    int* vertices{};
    Face* faces{};

    std::array<int, SIZES> sizes = {};
};