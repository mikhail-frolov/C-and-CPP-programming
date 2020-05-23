/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading
// File Gift.h
// Version 1.0
// Date    2020/01/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
// Revision History
// -----------------------------------------------------------
// Name   Mikhail Frolov         Date  January 27, 2020           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_GIFT_H__
#define SDDS_GIFT_H__

namespace sdds {

const int MAX_DESC = 15;
const double MAX_PRICE = 999.99;
const int MAX_LENGTH = 20;

struct Wrapping{
    
    char *pattern = nullptr;
     
};

struct Gift {
    
    char g_description[MAX_DESC + 1];
    double g_price;
    int g_units;
    int wrap_layers;
    Wrapping* wrap = nullptr;
    
};

void gifting(double&);
void gifting(char*);
void gifting(int&);
void display(const Gift&);
void gifting(Gift&);
bool wrap(Gift&);
bool unwrap(Gift&);
}
#endif /* Gift_h */
