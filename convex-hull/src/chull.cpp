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

ConvexHull::ConvexHull(Point* points, int* vertices, Face* faces, const int sizes[SIZES]) {
    this->points = points;
    this->vertices = vertices;
    this->faces = faces;

    for(int i = 0; i < SIZES; ++i){
        this->sizes[i] = sizes[i];
    }
}

void ConvexHull::save() {
    try{
        std::ofstream points_file   (POINTS_FILE, WRITE_FILE);
        std::ofstream vertices_file (VERTICES_FILE, WRITE_FILE);
        std::ofstream faces_file    (FACES_FILE, WRITE_FILE);

        /* Points */
        auto* pointsPtr     = this->points;
        auto* verticesPtr   = this->vertices;
        auto* facesPtr      = this->faces;

        for(int i = 0; i < sizes[POINTS_IDX]; ++i){
            points_file << pointsPtr[i][X] << SEPARATOR
                        << pointsPtr[i][Y] << SEPARATOR
                        << pointsPtr[i][Z] << '\n';
        }

        for(int i = 0; i < sizes[VERTICES_IDX]; ++i){
            vertices_file << verticesPtr[i];
            if(i != sizes[VERTICES_IDX] - 1){
                vertices_file << SEPARATOR;
            }
            else{
                vertices_file << '\n';
            }
        }

        for(int i = 0; i < sizes[FACES_IDX]; ++i){
            faces_file  << facesPtr[i][0] << SEPARATOR
                        << facesPtr[i][1] << SEPARATOR
                        << facesPtr[i][2] << '\n';
        }

        points_file.close();
        vertices_file.close();
        faces_file.close();
    }
    catch(const std::ofstream::failure& e){
        std::cout << "ERROR: ostream failed.";
    }
}
