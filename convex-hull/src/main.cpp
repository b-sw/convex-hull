/*
*	Name:		main.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "test.hpp"

int main(int argc, char* argv[]){
    unitTests();

    /* TEMPORARY TESTS */
//    std::cout << "Point test: ";
//    auto* p = new Point(0.32, 0.75, 0.19);
//    (*p)[0] = 5;
//    std::cout << (*p)[0];
//
//    std::cout << "\nEdge test: ";
//    int pts[2] = {5,8};
//    Edge* e = new Edge(pts);
//    (*e)[1] = 10;
//    std::cout << (*e)[1];
//
//    std::cout << "\nFace test: ";
//    int pts2[3] = {1, 2, 3};
//    Face* f = new Face(pts2);
//    (*f)[2] = 5;
//    std::cout << (*f)[2] << '\n';
//
//    int v[3] = {1, 2, 3};
//    int sizes[3] = {1, 1, 1};
//    auto* chull = new ConvexHull(p, v, f, sizes);
//
//    chull->save();

}