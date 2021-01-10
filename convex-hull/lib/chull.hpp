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

#include <fstream>
#include <iostream>
#include <vector>
#include <set>

#include "face.hpp"

#define POINTS_FILE "..\\convex-hull\\visuals\\points.data"
#define VERTICES_FILE "..\\convex-hull\\visuals\\vertices.data"
#define FACES_FILE "..\\convex-hull\\visuals\\faces.data"
#define SEPARATOR ';'
#define WRITE_FILE std::ios::out

class ConvexHull{
public:
    explicit ConvexHull(std::vector<Point> points, std::set<int> vertices, std::set<std::set<int>> faces);
    explicit ConvexHull(std::vector<Point> points, const std::vector<Face>& faces);
    ConvexHull() = default;
    ~ConvexHull() = default;

    void save();

private:
    std::vector<Point> points;
    std::set<int> vertices;
    std::set<std::set<int>> faces;

    int getIndex(Point point);
};