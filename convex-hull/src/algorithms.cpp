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

ConvexHull algorithms::giftWrapping(const std::vector<Point>& points) {
    std::vector<Face> faces;
    std::vector<Edge> visitedEdges;

    Face first = firstFace(points);
    faces.push_back(first);
    int facesSize = 1;
    for(int i=0; i<facesSize; ++i){
        Face curFace = faces.at(i);
        for(int i=0; i<FACE_POINTS; ++i){
            Point edgePoint1 = curFace[i];
            Point edgePoint2 = curFace[(i+1) % FACE_POINTS];
            Point oppositePoint = curFace[(i+2) % FACE_POINTS];
            Edge* edge = new Edge(edgePoint1, edgePoint2);
            if(std::find(visitedEdges.begin(), visitedEdges.end(), *edge) != visitedEdges.end()) continue;

            double maxAngle = 0.0;
            Point nextHullPoint;
            for(auto const& point : points){
                if(point == edgePoint1 || point == edgePoint2 || point == oppositePoint) continue;

                double angle = angleBetweenPlanes(edgePoint1, edgePoint2, oppositePoint, point);
                if(angle > maxAngle) {
                    maxAngle = angle;
                    nextHullPoint = point;
                }
            }
            Face* face = new Face(edgePoint1, edgePoint2, nextHullPoint);
            faces.push_back(*face);
            ++facesSize;
            visitedEdges.push_back(*edge);
        }
    }

    return *(new ConvexHull(points, faces));
}

//ConvexHull algorithms::incremental(const std::vector<Point>& points) {
//    std::vector<Face> faces;
//
//    std::vector<Face> firstTwoFaces = firstFour(points);
//    faces.push_back(firstTwoFaces.at(0));
//    faces.push_back(firstTwoFaces.at(1));
//    std::vector<Point> pointCloud = points;
//    pointCloud.erase(std::remove(pointCloud.begin(), pointCloud.end(), firstTwoFaces.at(0)[0]), pointCloud.end());
//    pointCloud.erase(std::remove(pointCloud.begin(), pointCloud.end(), firstTwoFaces.at(0)[1]), pointCloud.end());
//    pointCloud.erase(std::remove(pointCloud.begin(), pointCloud.end(), firstTwoFaces.at(0)[2]), pointCloud.end());
//    pointCloud.erase(std::remove(pointCloud.begin(), pointCloud.end(), firstTwoFaces.at(1)[2]), pointCloud.end());
//    for(int i=0; i<pointCloud.size(); ++i){
//        for(auto face : faces){
//
//        }
//    }
//
//
//
//    return *(new ConvexHull());
//}

ConvexHull algorithms::divideNConquer(const std::vector<Point>& points) {
    return *(new ConvexHull());
}

bool algorithms::isOutside(Point p1, Point p2, Point p3, Point pt) {
/*
 p1[X] p1[Y] p1[Z] 1
 p2[X] p2[Y] p2[Z] 1
 p3[X] p3[Y] p3[Z] 1
 pt[X] pt[Y] pt[Z] 1
*/
    double det =   1 * p2[Z] * p3[Y] * pt[X] - p1[Z] * 1 * p3[Y] * pt[X] - 1 * p2[Y] * p3[Z] * pt[X] + p1[Y] * 1 * p3[Z] * pt[X]
                 + p1[Z] * p2[Y] * 1 * pt[X] - p1[Y] * p2[Z] * 1 * pt[X] - 1 * p2[Z] * p3[X] * pt[Y] + p1[Z] * 1 * p3[X] * pt[Y]
                 + 1 * p2[X] * p3[Z] * pt[Y] - p1[X] * 1 * p3[Z] * pt[Y] - p1[Z] * p2[X] * 1 * pt[Y] + p1[X] * p2[Z] * 1 * pt[Y]
                 + 1 * p2[Y] * p3[X] * pt[Z] - p1[Y] * 1 * p3[X] * pt[Z] - 1 * p2[X] * p3[Y] * pt[Z] + p1[X] * 1 * p3[Y] * pt[Z]
                 + p1[Y] * p2[X] * 1 * pt[Z] - p1[X] * p2[Y] * 1 * pt[Z] - p1[Z] * p2[Y] * p3[X] * 1 + p1[Y] * p2[Z] * p3[X] * 1
                 + p1[Z] * p2[X] * p3[Y] * 1 - p1[X] * p2[Z] * p3[Y] * 1 - p1[Y] * p2[X] * p3[Z] * 1 + p1[X] * p2[Y] * p3[Z] * 1;

    return det < 0;
}

Face algorithms::firstFace(const std::vector<Point>& points) {
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
                    return *(new Face(point1, point2, point3));
                }
            }
        }
    }
    return Face();
}

std::vector<Face> algorithms::firstFour(const std::vector<Point>& points){
    std::vector<Face> firstFaces;
    Face first = firstFace(points);
    firstFaces.push_back(first);
    Edge edge = *(new Edge(first[0], first[1]));
    for(auto const& point : points){
        if(point == edge[0] || point == edge[1] || point == first[2]) continue;
        bool isFace = true;
        for(auto const& pointExt : points){
            if(pointExt == edge[0] || pointExt == edge[1] || pointExt == point || pointExt == first[2]) continue;
            if(isOutside(edge[0], edge[1], point, pointExt)){
                isFace = false;
                break;
            }
        }
        if(isFace){
            firstFaces.push_back(*(new Face(edge[0], edge[1], point)));
            return firstFaces;
        }
    }
}

double algorithms::angleBetweenPlanes(Point edgePoint1, Point edgePoint2, Point point1, Point point2) {

    // First plane
    double a11 = edgePoint2[X] - edgePoint1[X];
    double b11 = edgePoint2[Y] - edgePoint1[Y];
    double c11 = edgePoint2[Z] - edgePoint1[Z];
    double a12 = point1[X] - edgePoint1[X];
    double b12 = point1[Y] - edgePoint1[Y];
    double c12 = point1[Z] - edgePoint1[Z];
    double a1 = b11 * c12 - b12 * c11;
    double b1 = a12 * c11 - a11 * c12;
    double c1 = a11 * b12 - b11 * a12;

    // First plane
    double a21 = edgePoint2[X] - edgePoint1[X];
    double b21 = edgePoint2[Y] - edgePoint1[Y];
    double c21 = edgePoint2[Z] - edgePoint1[Z];
    double a22 = point2[X] - edgePoint1[X];
    double b22 = point2[Y] - edgePoint1[Y];
    double c22 = point2[Z] - edgePoint1[Z];
    double a2 = b21 * c22 - b22 * c21;
    double b2 = a22 * c21 - a21 * c22;
    double c2 = a21 * b22 - b21 * a22;

    double d = (a1 * a2 + b1 * b2 + c1 * c2);
    double e1 = sqrt(a1 * a1 + b1 * b1 + c1 * c1);
    double e2 = sqrt(a2 * a2 + b2 * b2 + c2 * c2);
    d = d / (e1 * e2);
    double pi = 3.14159;
    double angle = (180 / pi) * (acos(d));

    return angle;
}
