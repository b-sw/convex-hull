/*
*	Name:		preprocessing.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include <cmath>

#include "preprocessing.hpp"

std::vector<Point> preprocessing::preprocess(const std::vector<Point>& inputPoints, double d){
    std::vector<Point> outputPoints = {};

    double min_x = minCoord(inputPoints, X);
    double min_y = minCoord(inputPoints, Y);
    double min_z = minCoord(inputPoints, Z);
    double dim_x = maxCoord(inputPoints, X) - min_x;
    double dim_y = maxCoord(inputPoints, Y) - min_y;
    double dim_z = maxCoord(inputPoints, Z) - min_z;
    const int n_x = int( ceil(dim_x/d) );
    const int n_y = int( ceil(dim_y/d) );
    const int n_z = int( ceil(dim_z/d) );

    bool*** visited = new bool**[n_x];
    for(int i=0; i<n_x; ++i){
        visited[i] =  new bool*[n_y];
        for(int j=0; j<n_y; ++j){
            visited[i][j] = new bool[n_z];
            for(int k=0; k<n_z; ++k){
                visited[i][j][k] = false;
            }
        }
    }

    for(auto point : inputPoints){
        int i_x = int( floor((point[X] - min_x)/d) );
        int i_y = int( floor((point[Y] - min_y)/d) );
        int i_z = int( floor((point[Z] - min_z)/d) );
        if(!visited[i_x][i_y][i_z]){
            visited[i_x][i_y][i_z] = true;
            double center_x = min_x + d*(i_x + 0.5);
            double center_y = min_y + d*(i_y + 0.5);
            double center_z = min_z + d*(i_z + 0.5);
            outputPoints.push_back( *(new Point(center_x, center_y, center_z)) );
        }
    }

    return outputPoints;
}

double preprocessing::maxCoord(const std::vector<Point>& points, int dim){
    if(points.empty()) return 0;
    double maxVal = points.at(0)[dim];
    for(auto& point : points){
        if(point[dim] > maxVal){
            maxVal = point[dim];
        }
    }
    return maxVal;
}

double preprocessing::minCoord(const std::vector<Point>& points, int dim){
    if(points.empty()) return 0;
    double minVal = points.at(0)[dim];
    for(auto& point : points){
        if(point[dim] < minVal){
            minVal = point[dim];
        }
    }
    return minVal;
}

