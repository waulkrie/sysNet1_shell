/**
 *  myshell.cpp
 *  
 *  Andrew Bare (aob1) - Donte Gordon (dxg2)
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include <param.hpp>

// main
int main(int argc, const char** argv) {
    Param p;

    string input = "";
    while(input != "exit") {
        p.getArguments(input);
    }
    cout << "exiting..." << endl;
    return 0;
}
