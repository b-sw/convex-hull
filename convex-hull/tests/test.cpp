/*
*	Name:		test.cpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "../lib/test.hpp"

#define assertm(exp, msg) assert(((void)msg, exp))

bool unitTests(){
    typedef bool(*testFunctions) ( );
    static testFunctions tests[] = {
            testPoint,
            testEdge,
            testFace
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
    Point pts[2] = {Point(1, 2, 3),
                    Point(4, 5, 6)};
    Edge* e = new Edge(pts);
    assertm(e != nullptr, "Failed to construct an Edge.");
    return true;
}

bool testFace(){
    Point pts[3] = {Point(1, 2, 3),
                    Point(4, 5, 6),
                    Point(7, 8, 9)};
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