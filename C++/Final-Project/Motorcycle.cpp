#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cctype>
#include "Motorcycle.h"

using namespace std;
namespace sdds{

Motorcycle::Motorcycle() : Vehicle(){
    sidecar = false;
}

Motorcycle::Motorcycle(const char* lPlate,const char* mnm, int num) : Vehicle(lPlate, mnm, num){
   if (lPlate == nullptr || mnm == nullptr || strlen(lPlate) > 8 || strlen(mnm) < 2) {
       Vehicle::setEmpty();
       sidecar = false;
   }
}

    istream& Motorcycle::read(istream& istr){
        if (this->isCsv()) {
            Vehicle::read(istr);
      int h_car;
           
            istr >> h_car;
            istr.ignore(1000, '\n');
            sidecar = bool(h_car);
            
        } else {
         char choice[6];
                      cout << endl;
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(istr);
                  cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
                     istr >> choice;
                     istr.clear();
                     istr.ignore(1000, '\n');
                     
                        while(strlen(choice) > 1) {
                            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                            istr >> choice;
                            istr.clear();
                            istr.ignore(1000, '\n');
                            
                        }
            cout << endl;
            (choice[0]=='y' || choice[0]=='Y') ? sidecar = true : sidecar = false;
        }
        
       return istr;
    }

    
    ostream& Motorcycle::write(ostream& ostr) const{
        
        if (!this->isEmpty()) {
            if (this->isCsv()) {
               ostr << "M,";
                Vehicle::write(ostr);
                ostr << sidecar << endl;
            } else {
            ostr << "Vehicle type: Motorcycle" << endl;
                Vehicle::write(ostr);
                if (sidecar == true) {
                    ostr << endl << "With Sidecar";
                } 
 ostr << endl; 
            }
        } else {
            ostr << "Invalid Motorcycle Object" << endl;
        }
        return ostr;
    }

}
