/*
*	Name:		test.hpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include "edge.hpp"
#include "face.hpp"
#include "generator.hpp"
#include "chull.hpp"
#include <cassert>
#include <vector>

bool unitTests();

bool testPoint();

bool testEdge();

bool testFace();

bool testGenerator();
