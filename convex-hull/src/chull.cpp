/*
*	Name:		chull.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "chull.hpp"

ConvexHull::ConvexHull(Point* points, int* vertices, Face* faces) {
    this->points = points;
    this->vertices = vertices;
    this->faces = faces;
}

void ConvexHull::save() {
    try{
        std::ofstream points_file   (POINTS_FILE, WRITE_FILE);
        std::ofstream vertices_file (VERTICES_FILE, WRITE_FILE);
        std::ofstream faces_file    (FACES_FILE, WRITE_FILE);
    }
    catch(const std::ofstream::failure& e){
        std::cout << "ERROR: Failed to open file.";
    }

    /* Points */
    auto* pointsPtr = this->points;
    auto* verticesPtr = this->vertices;
    auto* facesPtr = this->faces;

    // todo: zapisywanie do pliku

}
