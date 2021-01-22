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
#include "stopwatch.hpp"

int main(int argc, char* argv[]){
    unitTests();

    // TYMCZASOWE DEMO
//    int n = 20;
//    std::vector<Point> pts = generator::generatePoints(234099,n);
//    std::vector<Point> modelPts = preprocessing::preprocess(pts, 1.2);

    auto* stopwatch = new Stopwatch();
    stopwatch->examineAlgorithm(5, 1234, 1.4, 5, 2, 3, algorithms::giftWrapping);
    stopwatch->save();

//    ConvexHull ch = algorithms::incremental(modelPts);
//    ch.save();
}