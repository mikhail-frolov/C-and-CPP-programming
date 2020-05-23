/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: Parking.h
Version 1.0
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/12  Preliminary release
-----------------------------------------------------------*/
// Name  Mikhail Frolov     Date March 15,2020
/////////////////////////////////////////////////////////////////
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include <stdio.h>
#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Vehicle.h"
namespace sdds {

const int MAX_NO_OF_PS = 100;

class Parking {
    char* data;
    char* name = nullptr;
    Menu parking;
    Menu vehicle;
    
    int available_spots = 0;
    int number_of_spots = 0;
    int number_of_parked_v = 0;
    int spot_num = 0;
  
  Vehicle* p_spots[MAX_NO_OF_PS];
    // cannot get copied or assigned
      Parking(const Parking& x) = delete;
      Parking& operator=(const Parking& x) = delete;
    
       
    bool loadData();
    void saveData();
    bool isEmpty() const;
    void printStatus();
    void printReturn();
    void printParked() const;
    bool printClose();
    bool printExit() const;
    void parkIt();
    // other
    void displayVehicle() const;
    void displayParking() const;
    
    
public:
    int run();
    Parking();
    ~Parking();
    
    Parking(const char* datafile, int noOfSpots);
    
};

}

#endif

