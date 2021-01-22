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

namespace inputHandlers{
    int getInt(int argc, char* argv[], const char* flag);
    std::string getString(int argc, char* argv[], const char* flag);
}