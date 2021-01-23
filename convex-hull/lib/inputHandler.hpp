/*
*	Name:		point.hpp
*	Purpose:
*
*	Author:     Piotr Frątczak, Bartosz Świtalski
*
*	Warsaw University of Technology
*	Faculty of Electronics and Information Technology
*/
#pragma once

#include <string>
#include <iostream>
#include <cstring>

namespace inputHandlers{
    int getInt(int argc, char* argv[], const char* flag, int size);
    double getDouble(int argc, char* argv[], const char* flag, int size);
    std::string getString(int argc, char* argv[], const char* flag, int size);
}
