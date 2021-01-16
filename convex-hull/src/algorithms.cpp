/*
*	Name:		algorithms.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include <algorithm>
#include "algorithms.hpp"

ConvexHull algorithms::naive(const std::vector<Point>& points){
    std::vector<Face> chFaces;
    for(auto const& point1 : points){
        for(auto const& point2 : points){
            if(point2 == point1) continue;
            for(auto const& point3 : points){
                if(point3 == point2 || point3 == point1) continue;

                bool isFace = true;
                for(auto const& pointExt : points){
                    if(pointExt == point1 || pointExt == point2 || pointExt == point3) continue;
                    if(isVisible(point1, point2, point3, pointExt)){
                        isFace = false;
                        break;
                    }
                }
                if(isFace){
                    chFaces.push_back(*(new Face(point1, point2, point3)) );
                }
            }
        }
    }
    return *(new ConvexHull(points, chFaces));
}

ConvexHull algorithms::giftWrapping(const std::vector<Point>& points) {
    std::vector<Face> chFaces;
    std::vector<Edge> visitedEdges;

    Face first = firstFace(points);
    chFaces.push_back(first);
    int facesSize = 1;
    for(int i=0; i<facesSize; ++i){
        Face curFace = chFaces.at(i);
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
            chFaces.push_back(*face);
            ++facesSize;
            visitedEdges.push_back(*edge);
        }
    }

    return *(new ConvexHull(points, chFaces));
}

ConvexHull algorithms::incremental(const std::vector<Point>& points) {
    std::vector<Face> chFaces;

    const int four = 4;
    for(int i=0; i<four; ++i){
        Point p1 = points.at(i);
        Point p2 = points.at((i+1) % four);
        Point p3 = points.at((i+2) % four);
        chFaces.push_back(*(new Face(p1, p2, p3)) );
    }

    for(int i=4; i<points.size(); ++i){
        std::vector<Face> visibleFaces;
        for(auto face : chFaces){
            if(isVisible(face, points.at(i))) visibleFaces.push_back(face);
        }

        if(visibleFaces.empty()) continue;
        else {
            std::vector<Edge> borderEdges;
            for(auto visibleFace : visibleFaces){
                std::vector<Edge> faceEdges = visibleFace.getEdges();
                for(auto edge : faceEdges){
                    auto search = std::find(borderEdges.begin(), borderEdges.end(), edge);
                    if(search != borderEdges.end()){
                    /* if a border already appears in the set, it is a part of 2 visible faces,
                     * therefore it is not a border edge */
                        borderEdges.erase(search, borderEdges.end());
                    }
                    else {
                        borderEdges.push_back(edge);
                    }
                }
                chFaces.erase(std::remove(chFaces.begin(), chFaces.end(), visibleFace), chFaces.end());
            }
            for(auto edge : borderEdges){
                chFaces.push_back(*(new Face(edge[0], edge[1], points.at(i))) );
            }
        }
    }

    return *(new ConvexHull(points, chFaces));
}

ConvexHull algorithms::divideNConquer(std::vector<Point> points) {
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b){
        return a[X] < b[X];
    });
    std::vector<Face> chFaces = recursiveHull(points);
    return *(new ConvexHull(points, chFaces));
}

// HELPER FUNCTIONS


bool algorithms::isVisible(Point p1, Point p2, Point p3, Point pt) {
/*
 p1[X] p1[Y] p1[Z] 1
 p2[X] p2[Y] p2[Z] 1
 p3[X] p3[Y] p3[Z] 1
 pt[X] pt[Y] pt[Z] 1
*/
    // determinant of the matrix above to calculate the volume of a tetrahedron described by given points
    double det =   1 * p2[Z] * p3[Y] * pt[X] - p1[Z] * 1 * p3[Y] * pt[X] - 1 * p2[Y] * p3[Z] * pt[X] + p1[Y] * 1 * p3[Z] * pt[X]
                 + p1[Z] * p2[Y] * 1 * pt[X] - p1[Y] * p2[Z] * 1 * pt[X] - 1 * p2[Z] * p3[X] * pt[Y] + p1[Z] * 1 * p3[X] * pt[Y]
                 + 1 * p2[X] * p3[Z] * pt[Y] - p1[X] * 1 * p3[Z] * pt[Y] - p1[Z] * p2[X] * 1 * pt[Y] + p1[X] * p2[Z] * 1 * pt[Y]
                 + 1 * p2[Y] * p3[X] * pt[Z] - p1[Y] * 1 * p3[X] * pt[Z] - 1 * p2[X] * p3[Y] * pt[Z] + p1[X] * 1 * p3[Y] * pt[Z]
                 + p1[Y] * p2[X] * 1 * pt[Z] - p1[X] * p2[Y] * 1 * pt[Z] - p1[Z] * p2[Y] * p3[X] * 1 + p1[Y] * p2[Z] * p3[X] * 1
                 + p1[Z] * p2[X] * p3[Y] * 1 - p1[X] * p2[Z] * p3[Y] * 1 - p1[Y] * p2[X] * p3[Z] * 1 + p1[X] * p2[Y] * p3[Z] * 1;

    // if the volume is < 0, the base of the tetrahedron (p1, p2, p3) is not visible from outside the hull
    return det < 0;
}

bool algorithms::isVisible(Face face, Point point) {
    return isVisible(face[0], face[1], face[2], point);
}

Face algorithms::firstFace(const std::vector<Point>& points) {
    // First face found with the naive method
    for(auto const& point1 : points){
        for(auto const& point2 : points){
            if(point2 == point1) continue;
            for(auto const& point3 : points){
                if(point3 == point2 || point3 == point1) continue;

                bool isFace = true;
                for(auto const& pointExt : points){
                    if(pointExt == point1 || pointExt == point2 || pointExt == point3) continue;
                    if(isVisible(point1, point2, point3, pointExt)){
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

double algorithms::angleBetweenPlanes(Point edgePoint1, Point edgePoint2, Point point1, Point point2) {
    // Edge points are lying on the intersection of two planes defined by 2 common edge points and another point

    // First plane's normal vector [a1, b1, c1]
    double a11 = edgePoint2[X] - edgePoint1[X];
    double b11 = edgePoint2[Y] - edgePoint1[Y];
    double c11 = edgePoint2[Z] - edgePoint1[Z];
    double a12 = point1[X] - edgePoint1[X];
    double b12 = point1[Y] - edgePoint1[Y];
    double c12 = point1[Z] - edgePoint1[Z];
    double a1 = b11 * c12 - b12 * c11;
    double b1 = a12 * c11 - a11 * c12;
    double c1 = a11 * b12 - b11 * a12;

    // Second plane's normal vector [a2, b2, c2]
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

std::vector<Face> algorithms::recursiveHull(const std::vector<Point>& points) {
    std::vector<Face> convexHull;
    if(points.size() == 4){
        for(int i=0; i<4; ++i){
            Point p1 = points.at(i);
            Point p2 = points.at((i+1) % 4);
            Point p3 = points.at((i+2) % 4);
            convexHull.push_back( *(new Face(p1, p2, p3)) );
        }
    }
    else {
        const std::size_t halfSize = points.size() / 2;
        std::vector<Point> points1(points.begin(), points.begin() + halfSize);
        std::vector<Point> points2(points.begin() + halfSize, points.end());
        std::vector<Face> chFaces1 = recursiveHull(points1);
        std::vector<Face> chFaces2 = recursiveHull(points2);
        convexHull = mergeHulls(chFaces1, chFaces2);
    }
    return convexHull;
}

std::vector<Face> algorithms::mergeHulls(std::vector<Face> hull1, std::vector<Face> hull2) {
    std::vector<Face> merged;
    return merged;
}