/*
*	Name:		time.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "stopwatch.hpp"

auto Stopwatch::timeAlgorithm(const std::vector<Point>& points, ConvexHull (*algorithm)(const std::vector<Point>&)) {
    auto stopwatchStart = std::chrono::high_resolution_clock::now();

    ConvexHull convexHull = algorithm(points);

    auto stopwatchStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( stopwatchStop - stopwatchStart ).count();
    return duration;
}

void Stopwatch::timeForN(int n, const std::vector<Point>& points, ConvexHull (*algorithm)(const std::vector<Point>&)) {
    for(int i=0; i<n; ++i){
        auto time = timeAlgorithm(points, algorithm);
        averageTime += time;
//        times.push_back(time);
    }
}

void Stopwatch::write() {
    try{
        std::ofstream times_file   (TIMES_FILE, std::ios::out);

        times_file << "average: " << averageTime << '\n';
//
//        for(auto const& time : times){
//            times_file << time << '\n';
//        }


        times_file.close();
    }
    catch(const std::ofstream::failure& e){
        std::cout << "ERROR: ostream failed.";
    }
}