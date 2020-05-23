// OOP244 Workshop 7: Inheritance
// File: Vehicle.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Vehicle.h"

namespace sdds {

void Vehicle::setEmpty(){
    
    m_speed = 0;
    m_noOfSeats = 0;
    
}

Vehicle::Vehicle(){
    setEmpty();
}

Vehicle::Vehicle(int speed, int seats){
    
    if (speed > 0 && seats > 0) {
        m_speed = speed;
        m_noOfSeats = seats;
    } else {
        setEmpty();
    }
}

bool Vehicle::finetune(){
    bool value = true;
    
    if (m_speed > MAX_SPEED) {
        m_speed = MIN_SPEED;
    }
    if (m_speed < MAX_SPEED && m_speed > MIN_SPEED){
        std::cout << "The car cannot be tuned" << std::endl;
        value = false;
    }
    return value;
}

std::ostream& Vehicle::display(std::ostream& os) const{
    
    if (m_speed >= MIN_SPEED && m_noOfSeats > 0) {
        os << "|" << m_speed << "|" << m_noOfSeats << std::endl;
    }
    if (m_speed > MAX_SPEED) {
        os << "Car has to be fine tuned for speed limit" << std::endl;
    }
    if (m_speed == 0 || m_noOfSeats == 0) {
        os << "This Car is not initiated" << std::endl;
    }
    
    return os;
}


std::istream& Vehicle::input(std::istream& in){
    
    int speed;
    int seats;
    
    std::cout <<  "Enter the Vehicle`s speed: ";
    in >> speed;
    
    std::cout << "Enter no of seats: ";
    in >> seats;
    
    Vehicle temp(speed, seats);

    if (temp.m_speed != 0) {
        *this = temp;
    }
    return in;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v){
    v.display(os);
    return os;
}

std::istream& operator>>(std::istream& in, Vehicle& V){
    V.input(in);
    return in;
}

int Vehicle::getSpeed(){
    return m_speed;
}

int Vehicle::getSeats(){
    return m_noOfSeats;
}

}
