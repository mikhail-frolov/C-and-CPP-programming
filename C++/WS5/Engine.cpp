// OOP244 Workshop 5: Operator Overloading
// File: Engine.cpp
// Version: 1.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////
// Name  Mikhail Frolov  Date February 13th 2020
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <string>
#include <cctype>
#include <iostream>
#include "Engine.h"
using namespace std;
namespace sdds{

Engine::Engine(){
    e_type[0] = '\0';
    e_size = 0;
}

Engine::Engine( const char* type1, double size1){
    if (size1 > 0 && type1 != nullptr) {
         
        strcpy(e_type, type1);
        e_size = size1;
        
    } else {
        e_type[0] = '\0';
        e_size = 0;
    }
}

void Engine::setType(const char* e) {
    strcpy(e_type, e);
}


void Engine::setSize(double x) {
    e_size = x;
}

double Engine::get() const{
    return this->e_size;
}

char Engine::getE_type() const{
    
    return *this->e_type;
    
}

void Engine::display() const{
    
    cout << e_size << " liters - " << e_type << endl;
    
}

Engine::~Engine(){

}
}
