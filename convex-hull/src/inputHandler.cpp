/*
*	Name:		point.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#include "inputHandler.hpp"

int inputHandlers::getInt(int argc, char **argv, const char* flag) {
    for(int i = 0; i < argc; ++i){
        if(argv[i] == flag) return std::stoi(argv[i+1]);
    }

    return -1;
}

std::string inputHandlers::getString(int argc, char **argv, const char* flag) {
    for(int i = 0; i < argc; ++i){
        if(argv[i] == flag) return argv[i+1];
    }

    return "";
}