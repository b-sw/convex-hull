/*
*	Name:		generator.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include <vector>
#include <random>

#include "point.hpp"

#define MU 0
#define VAR 10

namespace generator{
    std::vector<Point> generatePoints(int seed, int n);
};