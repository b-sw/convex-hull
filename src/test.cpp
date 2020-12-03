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
    typedef bool( *testFunctions ) ( );
    static testFunctions tests[] = {
            testPoint,
            testEdge,
            testFace
    };

    for( int i = 0 ; i < TEST_NUM ; ++i ) {
        tests[i]();
    }

    return true;
}

bool testPoint(){
    Point* p = new Point(1, 2, 3);
    assertm( p != NULL, "Failed to construct a Point.");
    return true;
}

bool testEdge(){
    Point pts[2] = {Point(1, 2, 3),
                    Point(4, 5, 6)};
    Edge* e = new Edge(pts);
    assertm(e != NULL, "Failed to construct an Edge.");
    return true;
}

bool testFace(){
    Point pts[3] = {Point(1, 2, 3),
                    Point(4, 5, 6),
                    Point(7, 8, 9)};
    Face* f = new Face(pts);
    assertm(f != NULL, "Failed to construct a Face.");
    return true;
}