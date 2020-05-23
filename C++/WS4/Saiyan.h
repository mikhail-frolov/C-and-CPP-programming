/// OOP244 Workshop 4: Constructors
// File: SaiyanMain.cpp
// Version: 1.1
// Date: 1/24/2020
// Author: Mohammad Shamas
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////
// Name  Mikhail Frolov    Date February 10th 2020
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__
#include "Utils.h"
namespace sdds{

class Saiyan {
    
    char * m_name;
    int m_dob;
    int m_power;
    bool m_super;
    int m_level = 0;
    
public:
    
         Saiyan();
         Saiyan(const char* name, int d_of_b , int ppower);
        ~Saiyan();
    bool isSuper() const;
    bool isValid()const;
    void setEmpty();
    void display() const;
    void set(const char* name, int dob, int power, int level = 0, bool super = false);
    bool hasLost( Saiyan& other);
   void getName(char* name);
    void powerup();
};

}





#endif // !SDDS_UTILS_H__


