/*
*	Name:		main.cpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "test.hpp"
#include "stopwatch.hpp"
#include "inputHandler.hpp"

#define READ_FROM_FILE 5
#define AUTOMATIC_GENERATION 9
#define AUTOMATIC_TESTING 13

#define FLAG_IN "-in"
#define FLAG_N "-n"
#define FLAG_D "-d"
#define FLAG_SEED "-seed"
#define FLAG_P "-p"
#define FLAG_STEP "-step"
#define FLAG_R "-r"
#define FLAG_A "-a"

int main(int argc, char* argv[]){
    unitTests();

    if(argc == READ_FROM_FILE){
        std::string inFile = inputHandlers::getString(argc, argv, FLAG_IN, 3);
        std::string algorithm = inputHandlers::getString(argc, argv, FLAG_A, 2);

        std::vector<Point> pts = getPointsFromFile(inFile);

        ConvexHull chull;

        if(algorithm == "naive"){
            chull = algorithms::naive(pts);
        }else if(algorithm == "giftWrapping"){
            chull = algorithms::giftWrapping(pts);
        }else if(algorithm == "incremental"){
            chull = algorithms::incremental(pts);
        }

        chull.save();

    }else if(argc == AUTOMATIC_GENERATION){
        int n = inputHandlers::getInt(argc, argv, FLAG_N, 2);
        double d = inputHandlers::getDouble(argc, argv, FLAG_D, 2);
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED, 5);
        std::string algorithm = inputHandlers::getString(argc, argv, FLAG_A, 2);

        std::vector<Point> pts = generator::generatePoints(seed, n);
        std::vector<Point> processedPts = preprocessing::preprocess(pts, d);

        ConvexHull chull;
        if(algorithm == "naive"){
            chull = algorithms::naive(processedPts);
        }else if(algorithm == "giftWrapping"){
            chull = algorithms::giftWrapping(processedPts);
        }else if(algorithm == "incremental"){
            chull = algorithms::incremental(processedPts);
        }

        chull.save();

    }else if(argc == AUTOMATIC_TESTING){
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED, 5);
        int n = inputHandlers::getInt(argc, argv, FLAG_N, 2);
        int p = inputHandlers::getInt(argc, argv, FLAG_P, 2);
        int step = inputHandlers::getInt(argc, argv, FLAG_STEP, 5);
        int r = inputHandlers::getInt(argc, argv, FLAG_R, 2);
        std::string algorithm = inputHandlers::getString(argc, argv, FLAG_A, 2);

        auto* stopwatch = new Stopwatch();
        stopwatch->examineAlgorithm(n, seed, p, step, r, algorithms::naive);
        stopwatch->save();

    }else{
        std::cout << "No to klaps" << std::endl;
        // TYMCZASOWE DEMO

        int n = 100; //-> 260
        int seed = 96879;
        int problems = 10;
        int step = 50;
        int runs = 5;

        auto* stopwatch = new Stopwatch();
        stopwatch->examineAlgorithm(n, seed, problems, step, runs, algorithms::naive);
        stopwatch->save();
    }

}
