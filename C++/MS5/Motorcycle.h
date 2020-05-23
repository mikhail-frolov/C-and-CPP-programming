#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include <stdio.h>
#include "Vehicle.h"

namespace sdds{

class Motorcycle : public Vehicle {
  
    bool sidecar;

public:
    Motorcycle();
    Motorcycle(const char* lPlate,const char* mnm, int num = 0);
    Motorcycle(const Motorcycle& x) = delete;
    Motorcycle& operator=(const Motorcycle& x) = delete;
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;
    
};
}
#endif /* Motorcycle_hpp */
