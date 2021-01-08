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

ConvexHull::ConvexHull(std::vector<Point> points, std::vector<int> vertices, std::vector<Face> faces) {
    this->points = points;
    this->vertices = vertices;
    this->faces = faces;

}

void ConvexHull::save() {
    try{
        std::ofstream points_file   (POINTS_FILE, WRITE_FILE);
        std::ofstream vertices_file (VERTICES_FILE, WRITE_FILE);
        std::ofstream faces_file    (FACES_FILE, WRITE_FILE);

        for(auto const& point : points){
            points_file << point[X] << SEPARATOR
                        << point[Y] << SEPARATOR
                        << point[Z] << '\n';
        }

        for(auto it = vertices.begin(); it != vertices.end(); ++it){
            vertices_file << *it;
            if(it != vertices.end()){
                vertices_file << SEPARATOR;
            }
        }
        vertices_file << '\n';

        for(auto const& face : faces){
            faces_file  << face[0] << SEPARATOR
                        << face[1] << SEPARATOR
                        << face[2] << '\n';
        }

        points_file.close();
        vertices_file.close();
        faces_file.close();
    }
    catch(const std::ofstream::failure& e){
        std::cout << "ERROR: ostream failed.";
    }
}
