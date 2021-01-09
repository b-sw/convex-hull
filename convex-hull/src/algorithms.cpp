/*
*	Name:		algorithms.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "algorithms.hpp"

ConvexHull algorithms::naive(const std::vector<Point>& points){
    std::vector<Face> faces;
    for(auto const& point1 : points){
        for(auto const& point2 : points){
            if(point2 == point1) continue;
            for(auto const& point3 : points){
                if(point3 == point2 || point3 == point1) continue;

                bool isFace = true;
                for(auto const& pointExt : points){
                    if(pointExt == point1 || pointExt == point2 || pointExt == point3) continue;
                    if(isOutside(point1, point2, point3, pointExt)){
                        isFace = false;
                        break;
                    }
                }
                if(isFace){
                    faces.push_back( *(new Face(point1, point2, point3)) );
                }
            }
        }
    }
    return *(new ConvexHull(points, faces));
}

ConvexHull algorithms::giftWrapping(std::vector<Point> points) {
    return *(new ConvexHull());
}

ConvexHull algorithms::incremental(std::vector<Point> points) {
    return *(new ConvexHull());
}

ConvexHull algorithms::divideNConquer(std::vector<Point> points) {
    return *(new ConvexHull());
}

bool algorithms::isOutside(Point p1, Point p2, Point p3, Point pt) {
/*
 p1[X] p1[Y] p1[Z] 1
 p2[X] p2[Y] p2[Z] 1
 p3[X] p3[Y] p3[Z] 1
 pt[X] pt[Y] pt[Z] 1
*/
    double det =   1 * p2[Z] * pt[Y] * pt[X]
               - p1[Z] * 1 * pt[Y] * pt[X]
               - 1 * p2[Y] * p3[Z] * pt[X]
               + p1[Y] * 1 * p3[Z] * pt[X]
               + p1[Z] * p2[Y] * 1 * pt[X]
               - p1[Y] * p2[Z] * 1 * pt[X]
               - 1 * p2[Z] * p3[X] * pt[Y]
               + p1[Z] * 1 * p3[X] * pt[Y]
               + 1 * p2[X] * p3[Z] * pt[Y]
               - p1[X] * 1 * p3[Z] * pt[Y]
               - p1[Z] * p2[X] * 1 * pt[Y]
               + p1[X] * p2[Z] * 1 * pt[Y]
               + 1 * p2[Y] * p3[X] * pt[Z]
               - p1[Y] * 1 * p3[X] * pt[Z]
               - 1 * p2[X] * pt[Y] * pt[Z]
               + p1[X] * 1 * pt[Y] * pt[Z]
               + p1[Y] * p2[X] * 1 * pt[Z]
               - p1[X] * p2[Y] * 1 * pt[Z]
               - p1[Z] * p2[Y] * p3[X] * 1
               + p1[Y] * p2[Z] * p3[X] * 1
               + p1[Z] * p2[X] * pt[Y] * 1
               - p1[X] * p2[Z] * pt[Y] * 1
               - p1[Y] * p2[X] * p3[Z] * 1
               + p1[X] * p2[Y] * p3[Z] * 1;

    return det < 0;
}
