// OOP244 Workshop 5: Operator Overloading
// File: Ship.h
// Version: 1.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////
// Name  Mikhail Frolov  Date February 13th 2020
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__
#include "Engine.h"
#include <stdio.h>
namespace sdds{

class Ship {
    
    Engine* eng_array;
    char* sh_type;
    int num_of_eng = 0;
    float distance = 0;
    
    
    
public:
    Ship();
    Ship(const char* type_of_ship,  Engine* engines, const int length);
    ~Ship();
    
    bool empty() const;
    float calculatePower() const;
    void display() const;
    Ship& operator+=(Engine e);
    friend bool operator==(const Ship&, const Ship&);
    void setEmpty();
   // bool isEmpty() const ;
};
bool operator<(const Ship&, double);
}

#endif 
