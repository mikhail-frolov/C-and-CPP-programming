#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cctype>
#include "Car.h"

using namespace std;
namespace sdds{

Car::Car() : Vehicle(){
    carwash = false;
}

Car::Car(const char* lPlate,const char* mnm, int num) : Vehicle(lPlate, mnm, num){
    if (lPlate == nullptr || mnm == nullptr || strlen(lPlate) > 8 || strlen(mnm) < 2) {
        Vehicle::setEmpty();
        carwash = false;
    }
}

istream& Car::read(istream& istr){
    if (this->isCsv()) {
     int carwashFlag;
                Vehicle::read(istr);
                istr >> carwashFlag;
                istr.ignore(100, '\n');
                carwash = bool(carwashFlag);
    } else {
        char choice[6];
        cout << endl;
        cout << "Car information entry" << endl;
        Vehicle::read(istr);
        cout << "Carwash while parked? (Y)es/(N)o: ";
           istr >> choice;
           istr.clear();
           istr.ignore(1000, '\n');
           
              while(strlen(choice) > 1) {
                  cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                  istr >> choice;
                  istr.clear();
                  istr.ignore(1000, '\n');
              }
        (choice[0]=='y' || choice[0]=='Y') ? carwash = true : carwash = false;
            }
  
    return istr;
}

ostream& Car::write(ostream& ostr) const{
    
    if (!this->isEmpty()) {
        if (this->isCsv()) {
           ostr << "C,";
            Vehicle::write(ostr);
            ostr << carwash << endl;
        } else {
        ostr << "Vehicle type: Car" << endl;
            Vehicle::write(ostr);
            ostr << endl;
            if (this->carwash == true) {
                ostr << "With Carwash" << endl;
            } else {
                ostr << "Without Carwash" << endl;
            }
            
        }
    } else {
        ostr << "Invalid Car Object" << endl;
    }
    return ostr;
}

}
