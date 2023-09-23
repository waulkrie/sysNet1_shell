/**
 *  parse.hpp
 *  
 *  Andrew Bare (aob1) - Dante Gordon (dxg2)
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */

#ifndef _PARSE_HPP
#define _PARSE_HPP

#include "param.hpp"


class Parse
{
    private:
        Param* param;
        string input;
        int i;
        char fileName[MAXARGS];
    public:
        Parse();
        Parse(Param* param);
        ~Parse();
        void execute();


};
#endif