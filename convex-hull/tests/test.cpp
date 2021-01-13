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
    auto* p1 = new Point(1, 2, 3);
    auto* p2 = new Point(4, 5, 6);
    Edge* e = new Edge(*p1, *p2);
    assertm(e != nullptr, "Failed to construct an Edge.");
    return true;
}

bool testFace(){
    auto* p1 = new Point(1, 2, 3);
    auto* p2 = new Point(4, 5, 6);
    auto* p3 = new Point(7, 8, 9);
    Face* f = new Face(*p1, *p2, *p3);
    assertm(f != nullptr, "Failed to construct a Face.");
    return true;
}

bool testGenerator() {
    int seed = 1234;
    int n = 5;
    std::vector<Point> pts = generator::generatePoints(seed, n);
    assertm(pts.size() == n, "Failed to generate points.");
    return true;
}