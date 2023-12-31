/**
 *  param.hpp
 *
 *  Andrew Bare (aob1) - Dante Gordon (dxg2)
 *  Copyright 2023 UWF - CS. All rights reserved.
 *
 */

#ifndef _PARAM_CPP
#define _PARAM_CPP

#include "param.hpp"
#include <iostream>
using namespace std;

Param::Param()
{
    inputRedirect = outputRedirect = NULL;
    background = argumentCount = 0;
}

Param::~Param(){
    for(uint8_t i ; i < this->argumentCount; i++ ){
        delete this->argumentVector[i];
    }
    if(this->inputRedirect != NULL){
        delete this->inputRedirect;
    }
    if(this->outputRedirect != NULL){
        delete this->outputRedirect;
    }
}

void Param::addArgument(char* newArgument)
{

    // Allocate memory for the new argument and copy the token
    argumentVector[argumentCount] = new char[strlen(newArgument) + 1];
    strcpy(argumentVector[argumentCount++], newArgument);
    argumentVector[argumentCount] = NULL; // set last element to NULL

}

char** Param::consumeArguments(string& input)
{
    // get the arguments
    input.clear();
    cout << "myshell> " << flush;
    getline(cin, input);

    // tokenize the input
    char* token = strtok((char*)input.c_str(), " ");
    while (token != NULL) {
        // cout << "adding token: " << token << endl; // debug
        if (analyzeToken(token) == true)
            addArgument(token);
        token = strtok(NULL, " ");
    }

    return NULL;
}

char** Param::getArguments(){
    return this->argumentVector;
}

bool Param::analyzeToken(char* token)
{
    string temp = token;
    int i = temp.find('<');

    // input redirect
    if (i != -1) {
        if (temp.size() > 1) {
            temp = temp.substr(1);
            setInputRedirect(strdup(temp.c_str())); // free
            return false;
        } else
            cout << "error no filename found\n";
    }

    // output redirect
    temp = token;
    i = temp.find('>');
    if (i != -1) {
        if (temp.size() > 1) {
            temp = temp.substr(1);
            setOutputRedirect(strdup(temp.c_str()));
            return false;
        } else
            cout << "error no filename found \n";
    }

    temp = token;
    i = temp.find('&');
    if (i != -1) {
        setBackground(1);
        return false;
    } else
        setBackground(0);

    return true;
}
void Param::setInputRedirect(char* newInputRedirect)
{
    inputRedirect = newInputRedirect;
}

void Param::setOutputRedirect(char* newOutputRedirect)
{
    outputRedirect = newOutputRedirect;
}

void Param::setBackground(int newBackground)
{
    background = newBackground;
}

char* Param::getInputRedirect()
{
    return inputRedirect;
}

char* Param::getOutputRedirect()
{
    return outputRedirect;
}

int Param::getBackground()
{
    return background;
}

void Param::printParams()
{
    cout << "InputRedirect: [";
    if (inputRedirect != NULL) {
        cout << inputRedirect
             << "]"
             << endl;
    } else
        cout << "NULL"
             << "]"
             << endl;
    cout << "OutputRedirect: [";
    if (outputRedirect != NULL) {
        cout << outputRedirect
             << "]"
             << endl;
    } else {
        cout << "NULL"
             << "]"
             << endl;
    }
    cout << "Background: ["
         << background
         << "]"
         << endl
         << "ArgumentCount: ["
         << argumentCount
         << "]"
         << endl;
    for (int i = 0; i < argumentCount; i++)
        cout << "ArgumentVector["
             << i
             << "]: ["
             << argumentVector[i]
             << "]"
             << endl;
}

#endif
