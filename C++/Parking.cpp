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
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds{

Parking::Parking(){
    for (int i = 0; i < number_of_spots; i++) {
        p_spots[i] = nullptr;
    }
    number_of_spots = 0;
    delete [] name;
    name = nullptr;
}

Parking::Parking(const char* datafile, int noOfSpots){


if (noOfSpots < 10 || noOfSpots > MAX_NO_OF_PS) {
        number_of_spots = 0;
    available_spots = 0;
       number_of_parked_v = 0;
} else{

    number_of_spots = noOfSpots;
}

    if (datafile == nullptr || datafile[0] == '\0') {
             name = nullptr;
         } else {
            
             name = new char[strlen(datafile) + 1];
               strcpy(name, datafile);
             
             for (int i = 0; i < noOfSpots; i++) {
             p_spots[i] = nullptr;
                }
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
        
        vehicle.title = new char[29];
        strcpy(vehicle.title, "Select type of the vehicle:");
        
        vehicle.item[0].name = new char[4];
        strcpy(vehicle.item[0].name, "Car");
        
        vehicle.item[1].name = new char[11];
        strcpy(vehicle.item[1].name, "Motorcycle");
        
        vehicle.item[2].name = new char[7];
        strcpy(vehicle.item[2].name, "Cancel");
    } else {
        cout << "Error in data file" << endl;
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
        
        for (int i = 0; i < number_of_spots; i++) {
            delete p_spots[i];
            p_spots[i] = nullptr;
          }
        
    }

bool Parking::loadData(){
        bool value = false;
            int index;
            
            int x = number_of_parked_v;
                if (!isEmpty()) {
                        std::ifstream fin(name);
                            if (!fin) {
                                value = false;
                            }
                            else {
                                if (fin.is_open()) {
                                    value = true;
                                    char choice;
                                    
                                    while (x < number_of_spots) {
                                        choice = fin.get();
                                        if (fin.fail()) {
                                            fin.clear();
                                            fin.ignore(1000, '\n');
                                            x = number_of_spots;
                                        }
                                        else {
                                            Vehicle* vehicle;
                                            fin.ignore();
                                            choice = char(toupper(choice));
                                            if (choice == 'M') {
                                                vehicle = new Motorcycle();
                                                vehicle->setCsv(true);
                                                vehicle->read(fin);
                                                
                                            }
                                            else if (choice == 'C') {
                                                vehicle = new Car();
                                                vehicle->setCsv(true);
                                                vehicle->read(fin);
                                            }
                                            else {
                                                vehicle = nullptr;
                                            }
                                            
                                            if (vehicle != nullptr) {
                                                vehicle->setCsv(false);
                                                if (cin.fail()) {
                                                    delete[] vehicle;
                                                    vehicle = nullptr;
                                                    value = false;
                                                }
                                                else {
                                                    index = vehicle->getParkingSpot() - 1;
                                                    p_spots[index] = vehicle;
                                                    number_of_parked_v++;
                                                    value = true;
                                                }
                                            }
                                        }
                                    }
                
                                }
                            }
                        }
                        return value;
                    }


       
void Parking::saveData(){
    if (!isEmpty()) {
        ofstream file(name);
        if (file.is_open()) {
            for (int i = 0; i < number_of_spots; i++) {
                if (p_spots[i] != nullptr) {
                    p_spots[i]->setCsv(true);
                    p_spots[i]->write(file);
                }
            }
file.close();
        }
       
}
}

bool Parking::isEmpty() const{
    return name == nullptr ? true : false;
}

int Parking::run(){

    int menuOptn = 0;
    
    if (!isEmpty()) {
        int go = 1;
        while (go == 1) {
        printStatus();
        displayParking();
            cin >> menuOptn;
               cin.clear();
               cin.ignore(1000, '\n');
            
            
            if (menuOptn == 1) {
                parkIt();

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
void Parking::printStatus(){
    available_spots = number_of_spots - number_of_parked_v;
    cout << "****** Seneca Valet Parking ******" << endl;
    cout << "*****  Available spots: " << left << setw(4) << available_spots << " *****" << endl;
}

void Parking::printReturn(){
   cout << "Return Vehicle" << endl;
    char li_plate[9];
    cout << "Enter Licence Plate Number: ";
    cin.get(li_plate, 9, '\n');
        
  
    
    while (strlen(li_plate) > 8 || strlen(li_plate) < 1) {
               for (int i = 0; (size_t)i < strlen(li_plate); i++) {
                   li_plate[i] = '\0';
               }
                   cout << "Invalid Licence Plate, try again: ";

                   cin.get(li_plate, 9, '\n');

           }
    
    for (int i = 0; (size_t)i < strlen(li_plate); i++) {
          li_plate[i] = toupper(li_plate[i]);
      }
           
           
    int flag = 0;
    char temp[9];
    for (int i = 0; i < number_of_spots; i++) {
        if (p_spots[i] != nullptr) {
            strcpy(temp, p_spots[i]->lic_plate);
            if (strcmp(temp, li_plate) == 0) {
                cout << endl << "Returning: " << endl;
                p_spots[i]->setCsv(false);
                p_spots[i]->write(cout);
                cout << endl;
                
                delete p_spots[i];
                
                p_spots[i] = nullptr;
                available_spots++;
                number_of_parked_v--;
                flag = 0;
                break;
                
            } else{
                flag = 1;
            }
           
        }
    }
    if (flag == 1) {
                    cout << endl << "License plate " << li_plate << " Not found" << endl << endl;
    }
    
}


void Parking::printParked() const {
    cout << "*** List of parked vehicles ***" << endl;
    
    for (int i = 0; i < number_of_spots; i++) {
        if (p_spots[i] != nullptr) {
            p_spots[i]->setCsv(false);
            p_spots[i]->write(cout);
             cout <<  "-------------------------------" << endl;
        }
    }
}


    bool Parking::printClose() {
    bool value = false;
    char choice[6];
    if (this->isEmpty()) {
        cout << "Closing Parking" << endl;
        value = true;
    } else {
        cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
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
        if (choice[0]=='n' || choice[0]=='N') {
            cout << "Aborted!" << endl;
            value = false;
        } else {
            cout << "Closing Parking" << endl;
            for (int i = 0; i < number_of_spots; i++) {
                if (p_spots[i] != nullptr){
                    cout << endl << "Towing request" << endl;
                    cout << "*********************" << endl;
                    p_spots[i]->write(cout);
                   
                    delete p_spots[i];
                    p_spots[i] = nullptr;
                    }
            }
            available_spots=number_of_spots;
            number_of_parked_v = 0;
               value = true;
        }
    }
    
    return value;
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
    if (choice[0]=='y' || choice[0]=='Y') {
        cout << "Exiting program!" << endl;
    }
    
    
    return((choice[0]=='y') || (choice[0]=='Y')) ? true : false;
}

void Parking::parkIt(){
    int flag = 0;
    int subOptn = 0;
    
    
    for (int i = 0; i < number_of_spots; i++) {
        if (p_spots[i] == nullptr) {
            flag = 1;
            break;
        } else {
            flag = 2;
        }
    }
    
    
    
    if (flag == 1) {
    displayVehicle();
    cin >> subOptn;
    cin.clear();
    cin.ignore(1000, '\n');
         Vehicle* V = nullptr;
    if (subOptn == 1) {
        
        V = new Car;
        V->setCsv(false);
        cin >> *V;
        number_of_parked_v++;
        available_spots--;
        
        for (int i = 0; i < number_of_spots; i++) {
              if (p_spots[i] == nullptr) {
                  p_spots[i] = V;

                  spot_num = i + 1;
                  V->setParkingSpot(spot_num);
                  
                  break;
              }
          }
          
             cout << endl << "Parking Ticket" << endl;
        cout << *V << endl;
           
    
    }
        
    if (subOptn == 2) {

        V = new Motorcycle;
               V->setCsv(false);
               cin >> *V;
        
        number_of_parked_v++;
        available_spots--;

        for (int i = 0; i < number_of_spots; i++) {
              if (p_spots[i] == nullptr) {
                  p_spots[i] = V;

                  spot_num = i + 1;
                  V->setParkingSpot(spot_num);
                  
                  break;
              }
          }
          
             cout << "Parking Ticket" << endl;
              cout << *V << endl;
    }
        
    if (subOptn == 3) {
    cout << "Parking cancelled" << endl;
}
        
    } else {
        cout << "Parking is full" << endl;
    }
    
}


void Parking::displayVehicle() const {
    
      cout << setfill(' ') << setw(vehicle.indentation * 4);
      cout << "" << vehicle.title << endl;
      
          for (int i = 0; i < 3; i++){
              cout << setfill(' ') << setw(vehicle.indentation*4);
              cout << "" << i + 1 << "- " << vehicle.item[i].name << endl;
              
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
