// OOP244 Workshop 7: Inheritance
// File: Vehicle.h
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
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include <stdio.h>

namespace sdds {

const int MIN_SPEED = 100;
const int MAX_SPEED = 140;

class Vehicle{
    
    int m_speed = 0;
    int m_noOfSeats = 0;
    
public:
    void setEmpty();
    Vehicle();
    Vehicle(int speed, int seats);
    bool finetune();
    int getSpeed();
    int getSeats();
    std::ostream& display(std::ostream& os) const;
    std::istream& input(std::istream& in);
};

std::ostream& operator<<(std::ostream& os, const Vehicle& v);
std::istream& operator>>(std::istream& in, Vehicle& V);

}

#endif /* Vehicle_h */
