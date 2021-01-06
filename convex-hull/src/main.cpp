/*
*	Name:		main.cpp
*	Purpose:
*
*	@author
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include <iostream>
#include "../lib/test.hpp"
#include "../lib/generator.hpp"

int main(int argc, char* argv[]){
    unitTests();
    std::vector<Point> points = Generator::generatePoints(1000, 10);
}