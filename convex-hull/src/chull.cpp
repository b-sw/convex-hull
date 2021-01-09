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

ConvexHull::ConvexHull(std::vector<Point> points, std::set<int> vertices, std::vector<std::array<int, FACE_POINTS>> faces) {
    this->points = points;
    this->vertices = vertices;
    this->faces = faces;

}

ConvexHull::ConvexHull(std::vector<Point> points, std::vector<Face> faces) {
    this->points = points;
    for(auto const& face : faces){
        std::array<int, FACE_POINTS> facePts;
        for(int i=0; i<FACE_POINTS; ++i){
            int index = getIndex(face[i]);
            if(index == -1) continue; // TODO: exception
            this->vertices.insert(index);
            facePts[i] = index;
        }
        this->faces.push_back(facePts);
    }
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

        for(auto it = vertices.begin(); it != vertices.end();){
            vertices_file << *it;
            if(++it != vertices.end()){
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

int ConvexHull::getIndex(Point point) {
    auto it = std::find(points.begin(), points.end(), point);
    if(it != points.end()){
        return it - points.begin();
    }
    // element not present in the vector
    return -1;
}

