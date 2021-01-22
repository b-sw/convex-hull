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

#define READ_FROM_FILE 7
#define AUTOMATIC_GENERATION 11
#define AUTOMATIC_TESTING 15

#define FLAG_IN "-in"
#define FLAG_OUT "-out"
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
        std::string outFile = inputHandlers::getString(argc, argv, FLAG_OUT, 4);
        std::string algorithm = inputHandlers::getString(argc, argv, FLAG_A, 2);
        //std::vector<Point> pts = getPointsFromFile(inFile);

        // todo: stopwach cos tam

    }else if(argc == AUTOMATIC_GENERATION){
        int n = inputHandlers::getInt(argc, argv, FLAG_N, 2);
        int d = inputHandlers::getInt(argc, argv, FLAG_D, 2);
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED, 5);
        std::string outFile = inputHandlers::getString(argc, argv, FLAG_OUT, 4);
        std::string algorithm = inputHandlers::getString(argc, argv, FLAG_A, 2);

        // todo: stopwatch cos tam

    }else if(argc == AUTOMATIC_TESTING){
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED, 5);
        int n = inputHandlers::getInt(argc, argv, FLAG_N, 2);
        int d = inputHandlers::getInt(argc, argv, FLAG_D, 2);
        int p = inputHandlers::getInt(argc, argv, FLAG_P, 2);
        int step = inputHandlers::getInt(argc, argv, FLAG_STEP, 5);
        int r = inputHandlers::getInt(argc, argv, FLAG_R, 2);
        std::string algorithm = inputHandlers::getString(argc, argv, FLAG_A, 2);

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
