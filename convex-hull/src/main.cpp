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
#include "preprocessing.hpp"

int main(int argc, char* argv[]){
    unitTests();

    // TYMCZASOWE DEMO
    int n = 3;
    std::vector<Point> pts = generator::generatePoints(1234,n);
    std::vector<Point> modelPts = preprocessing::preprocess(pts, 1.2);

    for(int i=0; i<n; ++i){
        std::cout << pts.at(i)[X] << " " << pts.at(i)[Y] << " " << pts.at(i)[Z] << " translated to:" << std::endl;
        std::cout << modelPts.at(i)[X] << " " << modelPts.at(i)[Y] << " " << modelPts.at(i)[Z] << std::endl << std::endl;
    }
}