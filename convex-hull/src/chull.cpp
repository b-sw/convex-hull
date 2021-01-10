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

#include <utility>

ConvexHull::ConvexHull(std::vector<Point> points, std::set<int> vertices, std::set<std::set<int>> faces) {
    this->points = std::move(points);
    this->vertices = std::move(vertices);
    this->faces = std::move(faces);

}

ConvexHull::ConvexHull(std::vector<Point> points, const std::vector<Face>& faces) {
    this->points = std::move(points);
    for(auto const& face : faces){
        std::set<int> facePts;
        for(int i=0; i<FACE_POINTS; ++i){
            int index = getIndex(face[i]);
            if(index == -1) continue; // TODO: exception
            this->vertices.insert(index);
            facePts.insert(index);
        }
        this->faces.insert(facePts);
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
            auto it = face.begin();
            faces_file << *it++ << SEPARATOR
                       << *it++ << SEPARATOR
                       << *it << '\n';
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

