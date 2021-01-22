/*
*	Name:		point.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include <fstream>
#include <vector>
#include <iostream>
#include "point.hpp"

#define SEPARATOR ';'

Point::Point(double x, double y, double z){
    this->coords[X] = x;
    this->coords[Y] = y;
    this->coords[Z] = z;
}

std::vector<Point> getPointsFromFile(const std::string& fileName) {
    std::ifstream file;
    std::vector<Point> pts;
    try{
        file.open(fileName);
        std::string x, y, z;

        do{
            for(int i = 0; i < POINT_COORDS; ++i){
                std::getline(file, x, SEPARATOR);
                std::getline(file, y, SEPARATOR);
                std::getline(file, z, '\n');

                pts.emplace_back(std::stod(x), std::stod(y), std::stod(z));
            }
        }while(!file.eof());

        file.close();

        return pts;

    }catch(const std::ifstream::failure& e){
        std::cout << "Exception opening/reading file";
    }

    return pts;

}
