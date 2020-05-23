#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <stdio.h>
#include "Vehicle.h"
using namespace std;
namespace sdds{

class Car : public Vehicle {
    
    bool carwash;

public:
    Car();
    Car(const char* lPlate,const char* mnm, int num = 0);
    Car(const Car& x) = delete;
    Car& operator=(const Car& x) = delete;
    std::istream& read(std::istream& istr = cin);
    std::ostream& write(std::ostream& ostr = cout) const;
    friend class Parking;
};

}

#endif /* Car_hpp */
