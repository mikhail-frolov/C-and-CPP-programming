#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cctype>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds{

void Vehicle::setEmpty(){
    lic_plate[0] = '\0';
    make_n_mod = nullptr;
    ps_num = 0;
}

Vehicle::Vehicle(){
    setEmpty();
}

Vehicle::Vehicle(const char* lPlate,const char* mnm, int num){
    if (lPlate == nullptr || mnm == nullptr || strlen(lPlate) > 8 || strlen(mnm) < 2) {
        setEmpty();
    } else {

    strcpy(lic_plate, lPlate);
        for (int i = 0; (size_t)i < strlen(lic_plate); i++) {
                   lic_plate[i] = toupper(lic_plate[i]);
               }
        make_n_mod = new char[strlen(mnm)+1];
    strcpy(make_n_mod, mnm);
        ps_num = num;
}
}

Vehicle::~Vehicle(){
    delete [] make_n_mod;
    
}

bool Vehicle::isEmpty() const{
    bool value = false;
    if (make_n_mod == nullptr || lic_plate[0] == '\0' ) {
        value = true;
    }
    return value;
}

char Vehicle::getLicensePlate() const{
    return lic_plate[0];
}

char* Vehicle::getMakeModel() const{
    return make_n_mod;
}

void Vehicle::setMakeModel(const char* model){
    if (make_n_mod != nullptr) {
        delete [] make_n_mod;
    }
    
    if (model == nullptr) {
        make_n_mod = nullptr;
    } else {
        make_n_mod = new char[strlen(model)+1];
        strcpy(make_n_mod, model);
    }
}

void Vehicle::setLicensePlate(const char* lplate){
    strcpy(lic_plate, lplate);
}

int Vehicle::getParkingSpot() const{
    return ps_num;
}

void Vehicle::setParkingSpot(int value){
    if (value < 0) {
        delete [] make_n_mod;
        setEmpty();
    } else {
        ps_num=value;
    }
}

bool operator==(const Vehicle& V1, const Vehicle& V2){
    bool value = false;
    
    for (int i = 0; (size_t)i < strlen(V2.lic_plate); i++) {
        if (toupper(V1.lic_plate[i]) == toupper(V2.lic_plate[i])) {
            value = true;
        } else {break;}
    }
    return value;
}

bool operator==(const Vehicle& V1, const char* string){
     bool value = false;
       
       for (int i = 0; (size_t)i < strlen(string); i++) {
           if (toupper(V1.lic_plate[i]) == toupper(string[i])) {
               value = true;
           } else {break;}
       }
       return value;
}


std::istream& Vehicle::read(std::istream& istr){
    if (!isCsv()) {
   // LICENCE PLATE
        cout << "Enter Licence Plate Number: ";
        istr.getline(lic_plate, '\n');
      
        
        while (strlen(lic_plate) > 8 || strlen(lic_plate) <= 0) {
            for (int i = 0; (size_t)i < strlen(lic_plate); i++) {
                lic_plate[i] = '\0';
            }
                cout << "Invalid Licence Plate, try again: ";
               istr.getline(lic_plate, '\n');
     
        }
        
        for (int i = 0; (size_t)i < strlen(lic_plate); i++) {
            lic_plate[i] = toupper(lic_plate[i]);
        }
        
   // MAKE AND MODEL
        //using string i decided toget input including whitespace
        string temp;
        cout << "Enter Make and Model: ";
        getline(istr, temp);
        
        while (temp.length() > 60 || temp.length() < 2) {
            
            for (int i = 0; (size_t)i < (temp.length() + 1); i++) {
                temp[i] = '\0';
            }
                 cout << "Invalid Make and model, try again: ";
                getline(istr, temp);
           
        }
                delete [] make_n_mod;
                make_n_mod = new char[temp.length() + 1];
        //in order to use strcpy() i need to convert the string using c_str()
        strcpy(make_n_mod, temp.c_str());
        
    } else {
        // PARKING SPOT
        istr >> ps_num;
        istr.ignore(1, ',');
        
        // LICENCE PLATE
        istr.getline(lic_plate, 8, ',');
        for (int i = 0; (size_t)i < strlen(lic_plate); i++) {
                lic_plate[i] = toupper(lic_plate[i]);
            }
    
        char temp[60] = {0};
        istr.getline(temp, 60, ',');
        delete [] make_n_mod;
        make_n_mod = new char[strlen(temp) + 1];
        strcpy(make_n_mod, temp);
    }

    if (istr.fail()) {
        this->setEmpty();
    }
    return istr;
}

std::ostream& Vehicle::write(std::ostream& ostr) const{
    if (this->isEmpty()) {
        ostr << "Invalid Vehicle Object" << endl;
    } else {
        if (isCsv()) {
            ostr << ps_num << "," << lic_plate << "," << make_n_mod << ",";
        } else {
            ostr << "Parking Spot Number: ";
            if (ps_num == 0) {
               ostr << "N/A";
            } else {
                ostr << ps_num;
            }
            ostr << endl;
            
            ostr << "Licence Plate: " << lic_plate << endl;
            ostr << "Make and Model: " << make_n_mod;
        }
    }
    return ostr;
}

}
