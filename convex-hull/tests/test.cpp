/*
*	Name:		test.cpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "test.hpp"

#define assertm(exp, msg) assert(((void)msg, exp))

bool unitTests(){
    typedef bool(*testFunctions) ( );
    static testFunctions tests[] = {
            testPoint,
            testEdge,
            testFace,
            testGenerator
    };

    for(auto & test : tests) {
        test();
    }

    return true;
}

bool testPoint(){
    auto* p = new Point(1, 2, 3);
    assertm( p != nullptr, "Failed to construct a Point.");
    return true;
}

bool testEdge(){
    int pts[2] = {5,8};
    Edge* e = new Edge(pts);
    assertm(e != nullptr, "Failed to construct an Edge.");
    return true;
}

bool testFace(){
    int pts[3] = {1, 2, 3};
    Face* f = new Face(pts);
    assertm(f != nullptr, "Failed to construct a Face.");
    return true;
}

bool testGenerator() {
    int seed = 1234;
    int n = 5;
    std::vector<Point> pts = Generator::generatePoints(seed, n);
    assertm(pts.size() == n, "Failed to generate points");
    return true;
}