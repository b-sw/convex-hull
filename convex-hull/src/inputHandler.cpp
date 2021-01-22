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

int inputHandlers::getInt(int argc, char **argv, const char* flag, int size) {
    for(int i = 0; i < argc; ++i){
        if(strncmp(argv[i], flag, size) == 0) return std::stoi(argv[i+1]);
    }

    return -1;
}

std::string inputHandlers::getString(int argc, char **argv, const char* flag, int size) {
    for(int i = 0; i < argc; ++i){
        if(strncmp(argv[i], flag, size) == 0) return argv[i+1];
    }

    return "";
}
