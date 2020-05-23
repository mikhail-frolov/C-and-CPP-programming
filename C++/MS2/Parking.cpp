/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
Version 1.0
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/12  Preliminary release
-----------------------------------------------------------*/
// Name  Mikhail Frolov     Date March 15,2020
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Menu.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds{

Parking::Parking(){
    name = nullptr;
}

Parking::Parking(const char * nname){
    if (nname == nullptr || nname[0] == '\0') {
             name = nullptr;
         } else {
            
             name = new char[strlen(nname) + 1];
               strcpy(name, nname);
         }
    if (this->loadData()) {
        //populating parking
        parking.count = 5;
        parking.indentation = 0;
        
        parking.title = new char[33];
        strcpy(parking.title, "Parking Menu, select an action:");
        
        parking.item[0].name = new char[13];
        strcpy(parking.item[0].name, "Park Vehicle");
        
        parking.item[1].name = new char[15];
        strcpy(parking.item[1].name, "Return Vehicle");
        
        parking.item[2].name = new char[21];
        strcpy(parking.item[2].name, "List Parked Vehicles");
        
        parking.item[3].name = new char[27];
        strcpy(parking.item[3].name, "Close Parking (End of day)");
        
        parking.item[4].name = new char[13];
        strcpy(parking.item[4].name, "Exit Program");
        
        //populating vehicle
        vehicle.count = 3;
        vehicle.indentation = 1;
        
        vehicle.title = new char[28];
        strcpy(vehicle.title, "Select type of the vehicle:");
        
        vehicle.item[0].name = new char[4];
        strcpy(vehicle.item[0].name, "Car");
        
        vehicle.item[1].name = new char[11];
        strcpy(vehicle.item[1].name, "Motorcycle");
        
        vehicle.item[2].name = new char[7];
        strcpy(vehicle.item[2].name, "Cancel");
    } else {
        cout << "Error in data file" << endl;
        delete [] name;
        name = nullptr;
    }
    
}

Parking::~Parking(){
    this->saveData();
    
    delete [] name;
    name = nullptr;
    
    delete [] parking.title;
    parking.title = nullptr;
    for (int i = 0; i < parking.count; i++) {
        delete [] parking.item[i].name;
        parking.item[i].name = nullptr;
    }
    
    delete [] vehicle.title;
    vehicle.title = nullptr;
    for (int i = 0; i < vehicle.count; i++) {
        delete [] vehicle.item[i].name;
        vehicle.item[i].name = nullptr;
    }
    
}

bool Parking::loadData() const{
    bool value = false;
    
    if (!isEmpty()) {
        cout << "loading data from " << name << endl;
        value = true;
    }
    return value;
}

void Parking::saveData() const{
    if (!isEmpty()) {
        cout << "Saving data into " << name << endl;
    }
}

bool Parking::isEmpty() const{
    return name == nullptr ? true : false;
}

int Parking::run(){
    int menuOptn = 0;
    int subOptn = 0;
    
    if (!isEmpty()) {
        int go = 1;
        while (go == 1) {
        printStatus();
        displayParking();
            cin >> menuOptn;
               cin.clear();
               cin.ignore(1000, '\n');
            
            
            if (menuOptn == 1) {
                displayVehicle();
                cin >> subOptn;
                  cin.clear();
                  cin.ignore(1000, '\n');
                  
                  if (subOptn == 1) {
                      cout << "Parking Car" << endl;
                  }
                      if (subOptn == 2) {
                          cout << "Parking Motorcycle" << endl;
                      }
                          if (subOptn == 3) {
                              cout << "Cancelled parking" << endl;
                          }

            }
            
            if (menuOptn == 2) {
                printReturn();
            }
            
            if (menuOptn == 3) {
                printParked();
            }
            if (menuOptn == 4) {
                
                if (printClose() == true) {
                    go = 0;
                }
            }
            
            if (menuOptn == 5) {

                if (printExit() == true) {
                    go = 0;
                }
            }
            
        }
    }
    
    return isEmpty() ? 1 : 0;
    
}

// print something ->
void Parking::printStatus() const{
    cout << "****** Seneca Valet Parking ******" << endl;
}

void Parking::printReturn() const{
    cout << "Returning Vehicle" << endl;
}

void Parking::printParked() const {
    cout << "Listing Parked Vehicles" << endl;
}

bool Parking::printClose() const{
    cout << "Closing Parking" << endl;
    return true;
}

bool Parking::printExit() const{
    char choice[6];
    cout << "This will terminate the program!" << endl;
    cout << "Are you sure? (Y)es/(N)o: ";
    cin >> choice;
    cin.clear();
    cin.ignore(1000, '\n');
    
       while(strlen(choice) > 1) {
           cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
           cin >> choice;
           cin.clear();
         cin.ignore(1000, '\n');
       }

  cout << "Exiting program!" << endl;
 
    return((choice[0]=='y') || (choice[0]=='Y')) ? true : false;
}

void Parking::parkIt() const{
    displayVehicle();
}

void Parking::displayVehicle() const {
    
      cout << setfill(' ') << setw(vehicle.indentation * 4 + strlen(vehicle.title));
      cout << vehicle.title << endl;
      
          for (int i = 0; i < 3; i++){
              cout << setfill(' ') << setw(vehicle.indentation*4+1);
              cout << i + 1 << "- " << vehicle.item[i].name << endl;
              
          }
              cout << setfill(' ') << setw(vehicle.indentation * 4);
              cout << "" << "> ";
}

void Parking::displayParking() const {
 
    
    cout << parking.title << endl;
        
            for (int i = 0; i < 5; i++){
                cout << i + 1 << "- " << parking.item[i].name << endl; }
                cout << "" << "> ";
   
}

}
