// OOP244 Workshop 7: Inheritance
// File: Car.cpp
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
#include "Car.h"


namespace sdds {

Car::Car(){
    setEmpty();
}

void Car::setEmpty(){
    
    Vehicle::setEmpty();
    m_carType[0] = '\0';
    m_regYear = 0;
    
}

Car::Car(const char* type, int year, int speed, int seats) : Vehicle(speed, seats){
    bool valid = type[0] != '\0' && year > MIN_YEAR && year != 0;
    
    if (valid) {
        strcpy(m_carType, type);
        m_regYear = year;
    } else {
        setEmpty();
    }
    
}

void Car::finetune(){
    if (m_regYear > MIN_YEAR) {
    
        if (Vehicle::finetune() == true) {
         std::cout << "This car is finely tuned to default speed" << std::endl;
        }
    }
    else {

    std::cout << "Car cannot be tuned and has to be scraped" << std::endl;
    }
    
}

std::ostream& Car::display(std::ostream& os) const{
    
    if (m_regYear != 0 || m_carType[0] != '\0') {
        os.setf(std::ios::fixed);
        os.width(20);
        os << std::left << m_carType;
        os << m_regYear;
        Vehicle::display(os);
    } else {
        os << "Car is not initiated yet" << std::endl;
    }
    return os;
}

std::istream& Car::input(std::istream& in){
    
    char type[MAX_CHAR];
    int year;
    
    std::cout <<  "Enter the car type: ";
    in.getline(type, MAX_CHAR);
    
    std::cout << "Enter the car registration year: ";
    in >> year;
    
    if (type[0] != '\0' && year != 0) {
       Vehicle::input(in);
        strcpy(m_carType, type);
        m_regYear = year;
    }
    if (year < MIN_YEAR){
        setEmpty();
    }
    
    return in;
}

std::ostream& operator<<(std::ostream& os, const Car& C){
    
    C.display(os);
    return os;
    
}

std::istream& operator>>(std::istream& in, Car& C){
 
    C.input(in);
    return in;
    
}
}

