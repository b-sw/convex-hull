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
	std::cout<<"jestesmy tu";
        std::string inFile = inputHandlers::getString(argc, argv, FLAG_IN, 3);
        std::string outFile = inputHandlers::getString(argc, argv, FLAG_OUT, 4);
        //std::vector<Point> pts = getPointsFromFile(inFile);
        std::cout << inFile << outFile;
        // todo: stopwach cos tam

    }else if(argc == AUTOMATIC_GENERATION){
	std::cout<<"ludzi tlum";
        int n = inputHandlers::getInt(argc, argv, FLAG_N, 2);
        int d = inputHandlers::getInt(argc, argv, FLAG_D, 2);
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED, 5);
        std::string outFile = inputHandlers::getString(argc, argv, FLAG_OUT, 4);
        std::cout << n << d << seed << outFile;
        // todo: stopwatch cos tam

    }else if(argc == AUTOMATIC_TESTING){
	std::cout<<"i mysli dookola";
        int seed = inputHandlers::getInt(argc, argv, FLAG_SEED, 5);
        int n = inputHandlers::getInt(argc, argv, FLAG_N, 2);
        int d = inputHandlers::getInt(argc, argv, FLAG_D, 2);
        int p = inputHandlers::getInt(argc, argv, FLAG_P, 2);
        int step = inputHandlers::getInt(argc, argv, FLAG_STEP, 5);
        int r = inputHandlers::getInt(argc, argv, FLAG_R, 2);
        std::cout << seed << n << d << p << step << r;
        // todo: stopwatch cos tam

    }else{
        std::cout << "No to klaps";
        // TYMCZASOWE DEMO

        auto* stopwatch = new Stopwatch();
        stopwatch->examineAlgorithm(5, 1234, 1.4, 5, 2, 3, algorithms::giftWrapping);
        stopwatch->save();
    }

}
