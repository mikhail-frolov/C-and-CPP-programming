// OOP244 Workshop 6: Encapsulation
// File: Basket.cpp
// Version: 1.1
// Date: 02/28/2020
// Author: Nargis Khan
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////
// Name  Mikhail Frolov  Date March 4th 2020
//
/////////////////////////////////////////////////////////////////
#include "Basket.h"
using namespace std;
namespace sdds {

void Basket::setEmpty(){
    
    m_fruitname = nullptr;
    m_qty = 0;
    m_price = 0.0;
    
}

Basket::Basket(){
    
    setEmpty();
    
}

Basket::Basket(const char* name, int quantity, double price) {
    
    if (name == nullptr || name[0] == '\0' || quantity < 1 || price < 0) {
        setEmpty();
    } else {
        
        setName(name);
        setQty(quantity);
        setPrice(price);
        
    }
}

Basket::Basket(const Basket& copyBasket){

    if (copyBasket.m_fruitname != nullptr) {
        setName(copyBasket.m_fruitname);
        this->setPrice(copyBasket.getPrice());
        this->setQty(copyBasket.getQty());
    } else {
        setEmpty();
    }
               
}

Basket::~Basket(){
    
    delete [] m_fruitname;
    m_fruitname = nullptr;
    
}

void Basket::setQty(int q){
    if (q > 0) {
        m_qty = q;
    } else {
        m_qty = 0;
    }
}

void Basket::setPrice(double p){
    if (p > 0) {
        m_price = p;
    } else {
        m_price = 0;
    }
}

void Basket::setName(const char* name){
    
    if (name[0] != '\0') {
        
        int len = strlen(name) + 1;
        m_fruitname = new char[len];
        strcpy(m_fruitname, name);
        
    } else {
        m_fruitname = nullptr;
    }
    
}

int Basket::getQty() const{
    return m_qty;
}

double Basket::getPrice() const{
    return m_price;
}

bool Basket::addPrice(double add){
    
    if (add > 0) {
         m_price += add;
    }
    return m_price;
}

ostream& Basket::display(ostream& os) const {
    
    if (m_fruitname == nullptr) {
        os << "The Basket has not yet been filled" << endl;
    } else {
        os << "Basket Details" << endl;
        os << "Name: " << m_fruitname << endl;
        os << "Quantity: " << m_qty << endl;
        os.setf(ios::fixed);
        os.precision(2);
        os << "Price: " << m_price << endl;
    }
    return os;
}

Basket& Basket::operator=(const Basket& copyA){
    
    if (this != &copyA) {
        this->setPrice(copyA.getPrice());
        this->setQty(copyA.getQty());
        delete [] this->m_fruitname;
        
        if (copyA.m_fruitname != nullptr) {
           
            setName(copyA.m_fruitname);
        
        } else {
            this->setEmpty();
        }
    }
    return *this;
}

bool Basket::operator==(const Basket& temp){
    
    return this->getPrice() == temp.getPrice() && this->getQty() == temp.getQty() && (strcmp(this->m_fruitname,temp.m_fruitname)==0);
    
}

bool Basket::operator!=(const Basket& temp1){
    
    return !(this->getPrice() == temp1.getPrice() && this->getQty() == temp1.getQty() && (strcmp(this->m_fruitname,temp1.m_fruitname)==0));
    
}

std::ostream& operator<<(ostream& os, const Basket& bsk){
    
    bsk.display(os);
    return os;
}

};
