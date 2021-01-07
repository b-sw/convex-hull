/*
*	Name:		main.cpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "test.hpp"
#include "../lib/generator.hpp"

int main(int argc, char* argv[]){
    unitTests();
    std::vector<Point> points = Generator::generatePoints(1000, 10);

    /* TEMPORARY TESTS */
    std::cout << "Point test: ";
    auto* p = new Point(1, 2, 3);
    (*p)[0] = 5;
    std::cout << (*p)[0];

    std::cout << "\nEdge test: ";
    int pts[2] = {5,8};
    Edge* e = new Edge(pts);
    (*e)[1] = 10;
    std::cout << (*e)[1];

    std::cout << "\nFace test: ";
    int pts2[3] = {1, 2, 3};
    Face* f = new Face(pts2);
    (*f)[2] = 5;
    std::cout << (*f)[2];

    int tmpVertices[3] = {1, 2, 3};
    auto* chull = new ConvexHull(p, tmpVertices, f);

    chull->save();

}