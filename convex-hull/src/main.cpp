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

#define READ_FROM_FILE 3
#define AUTOMATIC_GENERATION 9
#define AUTOMATIC_TESTING 11

#define FLAG_IN "-in"
#define FLAG_OUT "-out"
#define FLAG_N "-n"
#define FLAG_D "-d"
#define FLAG_SEED "-seed"
#define FLAG_P "-p"
#define FLAG_STEP "-step"
#define FLAG_R "-r"

int main(int argc, char* argv[]){
    unitTests();

    if(argc == READ_FROM_FILE){
        std::string inFile = inputHandlers::getString(argc, argv, FLAG_IN);
        std::string outFile = inputHandlers::getString(argc, argv, FLAG_OUT);
        std::vector<Point> pts = getPointsFromFile(inFile);
        std::cout << inFile << outFile;
        // todo: stopwach cos tam

    }else if(argc == AUTOMATIC_GENERATION){
        int n = inputHandlers::getInt(argc, argv, FLAG_N);
        int d = inputHandlers::getInt(argc, argv, FLAG_D);
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED);
        std::string outFile = inputHandlers::getString(argc, argv, FLAG_OUT);
        std::cout << n << d << seed << outFile;
        // todo: stopwatch cos tam

    }else if(argc == AUTOMATIC_TESTING){
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED);
        int n = inputHandlers::getInt(argc, argv, FLAG_N);
        int d = inputHandlers::getInt(argc, argv, FLAG_D);
        int p = inputHandlers::getInt(argc, argv, FLAG_P);
        int step = inputHandlers::getInt(argc, argv, FLAG_STEP);
        int r = inputHandlers::getInt(argc, argv, FLAG_R);
        std::cout << seed << n << d << p << step << r;
        // todo: stopwatch cos tam

    }else{
        std::cout << "No to klaps" << std::endl;
        // TYMCZASOWE DEMO

        int points       = 50;
        int seed         = 12345;
        double precision = 1.5;
        int problems     = 20;
        int step         = 3;
        int runs         = 10;

        auto* stopwatch = new Stopwatch();
        stopwatch->examineAlgorithm(points, seed, precision, problems, step, runs, algorithms::naive);
        stopwatch->save();
    }

}