/// OOP244 Workshop 4: Constructors
// File: SaiyanMain.cpp
// Version: 1.1
// Date: 1/24/2020
// Author: Mohammad Shamas
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////
// Name  Mikhail Frolov  Date February 10th 2020
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <cctype>
#include "Saiyan.h"
#include "Utils.h"
using namespace std;
namespace sdds{

Saiyan::Saiyan(){
     setEmpty();
}
Saiyan::Saiyan(const char* name, int d_of_b , int ppower){
    set(name, d_of_b, ppower);
    
}
Saiyan::~Saiyan(){
    delete [] m_name;
     m_name = nullptr;

}


bool Saiyan::isSuper() const{
    return m_super;
}

bool Saiyan::isValid()const{
    bool valid;
    if (m_name[0] == '\0' && m_dob == 0 && m_power == 0 && m_super == false && m_level == 0) {
       valid = false;
    } else {
        valid = true;
    }
    return valid;
}



void Saiyan::display() const{
    if (!isValid()) {
        cout << "Invalid Saiyan!" << endl;
    } else {
        cout << m_name << endl;
        cout << "DOB: " << m_dob << " Power: " << m_power << endl;
        if (!isSuper()) {
            cout << "Super Saiyan Ability: Not super Saiyan." << endl << endl;
        } else {
            cout << "Super Saiyan Ability: Super Saiyan." << endl;
            cout << "Super Saiyan level is: " << m_level << endl;
        }
        
    }
    
}
void Saiyan::set(const char* name, int dob, int power, int level , bool super){
    if (name == nullptr || name[0] == '\0' || dob >= 2020 || power <= 0 || level < 0) {
        
  setEmpty();
    
    } else {

            m_name = new char[strlen(name) + 1];
            
        strcpy(m_name, name);
       m_power = power;
        m_dob = dob;
        m_super = super;
        if (isSuper()) {
            m_level= level;
    }
    }
    }

bool Saiyan::hasLost( Saiyan& other){
    bool value = false;
    if (isValid() == true) {
        powerup();
        other.powerup();
    if ( m_power < other.m_power){
        value= true;
    }
    }
    return value;
}

void Saiyan::powerup(){
    
    if (isSuper() == true) {
        m_power = m_power * (m_level + 1);
    }
}
void Saiyan::setEmpty(){
    m_name = new char[1];
    m_name[0] = '\0';
    m_dob = 0;
    m_power = 0;
    m_super = false;
    m_level = 0;
}

}

