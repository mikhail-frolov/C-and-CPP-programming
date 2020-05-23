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
namespace sdds {

class Parking {
    
    char* name;
    Menu parking;
    Menu vehicle;
    
    // cannot get copied or assigned
      Parking(const Parking& x) = delete;
      Parking& operator=(const Parking& x) = delete;
    
       
    bool loadData() const;
    void saveData() const;
    bool isEmpty() const;
    void printStatus() const;
    void printReturn() const;
    void printParked() const;
    bool printClose() const;
    bool printExit() const;
    void parkIt() const;
    
    // other
    void displayVehicle() const;
    void displayParking() const;
    
    
public:
    int run();
    Parking();
    Parking(const char*);
    ~Parking();
};

}

#endif

