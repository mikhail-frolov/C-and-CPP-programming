#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "ReadWritable.h"
#include "Utils.h"
namespace sdds{

class Vehicle :public ReadWritable {
    char lic_plate[9];
    char* make_n_mod;
    int ps_num = 0;
    
public:
    Vehicle();
    Vehicle(const char* lPlate,const char* mnm, int num = 0);
    Vehicle(const Vehicle& x) = delete;
    Vehicle& operator=(const Vehicle& x) = delete;
    ~Vehicle();
    int getParkingSpot() const;
    void setParkingSpot(int value);
    friend bool operator==(const Vehicle& V1, const Vehicle& V2);
    friend bool operator==(const Vehicle& V1, const char* string);
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;
    
protected:
    void setEmpty();
    bool isEmpty() const;
    char getLicensePlate() const;
    char* getMakeModel() const;
    void setMakeModel(const char* model);
};

}
#endif
