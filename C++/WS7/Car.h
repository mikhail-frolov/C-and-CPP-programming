// OOP244 Workshop 7: Inheritance
// File: Car.h
// Version: 1.0
// Date: 02/28/2020
// Author: Nargis Khan
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////
// -----------------------------------------------------------
// Name  Mikhail Frolov     Date March 11,2020
// Nargis Khan
/////////////////////////////////////////////////////////////////
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <stdio.h>
#include "Vehicle.h"
namespace sdds{

const int MAX_CHAR = 20;
const int MIN_YEAR = 2000;

class Car : public Vehicle {
    
    char m_carType[MAX_CHAR + 1];
    int m_regYear;
    
public:
    Car();
    Car(const char*, int, int, int);
    void finetune();
    std::ostream& display(std::ostream& os) const;
    std::istream& input(std::istream& in);
    void setEmpty();
    
};

std::ostream& operator<<(std::ostream& os, const Car& C);
std::istream& operator>>(std::istream& in, Car& C);

}

#endif /* Car_hpp */
