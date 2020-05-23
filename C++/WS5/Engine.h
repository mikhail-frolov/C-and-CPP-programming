// OOP244 Workshop 5: Operator Overloading
// File: Engine.h
// Version: 1.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////
// Name  Mikhail Frolov  Date February 13th 2020
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__
namespace sdds{

const int MAX = 30;

class Engine {
    
    double e_size;
    char e_type[MAX + 1];
    
public:
    Engine();
    Engine( const char* type1, double size1);
    ~Engine();
    void setType(const char*);
    void setSize(double);
    double get() const;
    void display() const;
    char getE_type() const;
   
};

}

#endif 
