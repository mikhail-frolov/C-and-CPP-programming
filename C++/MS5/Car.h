#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <stdio.h>
#include "Vehicle.h"

namespace sdds{

class Car : public Vehicle {
    
    bool carwash;

public:
    Car();
    Car(const char* lPlate,const char* mnm, int num = 0);
    Car(const Car& x) = delete;
    Car& operator=(const Car& x) = delete;
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;
    
};

}

#endif /* Car_hpp */
