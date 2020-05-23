// OOP244 Workshop 6: Encapsulation
// File: Basket.h
// Version: 1.1
// Date: 02/28/2020
// Author: Nargis Khan
// Description:
// This file tests lab section of your workshop
///////////////////////////////////////////////
///Name  Mikhail Frolov  Date March 4th 2020
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_BASKET_H__
#define SDDS_BASKET_H__
#include <iostream>
#include <stdio.h>
#include<cstring>

namespace sdds{

class Basket {
    
    char * m_fruitname;
    int m_qty;
    double m_price;

public:
    Basket();
    Basket(const char*, int, double);
    Basket(const Basket&);
    ~Basket();
    
    void setName(const char*);
    void setQty(int);
    void setPrice(double);
    bool isempty() const;
    bool addPrice(double);
    std::ostream& display(std::ostream& os) const;
    
    Basket& operator=(const Basket&);
    bool operator==(const Basket&);
    bool operator!=(const Basket&);
    
    void setEmpty();
    int getQty() const;
    double getPrice() const;
};

std::ostream& operator<<(std::ostream& os, const Basket& bsk);

};
#endif /* Basket_h */
