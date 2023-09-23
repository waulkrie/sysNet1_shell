/**
 *  myshell.cpp
 *
 *  Andrew Bare (aob1) - Dante Gordon (dxg2)
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */

#include "parse.hpp"
#include <cstring>

// main
int main(int argc, const char** argv)
{
    bool debug_mode = false;

    // test for debug mode
    if (argc > 1 && (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-Debug") == 0)) {
        debug_mode = true;
    }

    string input = "";
    while (input != "exit") {
        Param p;
        p.consumeArguments(input);
        if (debug_mode) {
            p.printParams();
        }
        Parse par(&p);
        par.execute();
    }
    cout << "exiting..." << endl;
    return 0;
}
