// OOP244 Workshop 5: Operator Overloading
// File: Ship.cpp
// Version: 1.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////
// Name  Mikhail Frolov  Date February 13th 2020
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <string>
#include <cctype>
#include <iostream>
#include "Engine.h"
#include "Ship.h"
using namespace std;
namespace sdds{

Ship::Ship(){
    
    setEmpty();
}

Ship::Ship(const char* type_of_ship, Engine* engines, const int length){
    if (type_of_ship==nullptr || strlen(type_of_ship) > 6 || length < 1) {
       
        setEmpty();
     
    } else {
        
           sh_type = new char[strlen(type_of_ship) + 1];
        strcpy(sh_type, type_of_ship);
    
        Engine* new_eng = nullptr;
        new_eng = new Engine[length];
        num_of_eng = length;
        
        
      for (int i = 0 ; i < length; i++) {
          new_eng[i] = engines[i];
      }
        eng_array = new_eng;
        
      }
}

bool Ship::empty() const{
    bool value = false;
    
    if (sh_type == nullptr || num_of_eng == 0 ) {
        value = true;
    }
    
    return value;
    
}

void Ship::setEmpty(){
    
    sh_type=nullptr;
    num_of_eng = 0;
    distance = 0;
   
}
 

float Ship::calculatePower() const{
    float output_power = 0.0;
    
    for (int i = 0; i < num_of_eng; i++) {
        output_power += (eng_array[i].get() * 5) ;
    }
    
    return output_power;
}


void Ship::display() const{
    
    if (empty()) {
        cout << "No available data" << endl;
    } else {
        cout << sh_type << "-";
        cout.setf(ios::fixed);
        cout.width(6);
        cout.precision(2);
        cout << calculatePower() << endl;
        for (int i = 0 ; i < num_of_eng; i++) {
             eng_array[i].display();
        }
    }
}

Ship& Ship::operator+=(Engine e){
    
    if (num_of_eng < 1 || strlen(sh_type) > 7 || sh_type == nullptr) {
        cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
    } else {
          Engine* new_array = new Engine[num_of_eng + 1];
        
        for (int i = 0; i < num_of_eng; i++) {
            new_array[i] = eng_array[i];
        }
        new_array[num_of_eng] = e;

        delete [] eng_array;
        eng_array = nullptr;
        
        eng_array = new_array;
        num_of_eng++;
        
        
    }
    return *this;
}

bool operator==(const Ship& x, const Ship& y){
    bool value = false;
    if (x.calculatePower() == y.calculatePower()){
        value = true;
    }
    return value;
}

bool operator<(const Ship& a , double b){
    bool value = false;
    if (a.calculatePower() < b) {
        value = true;
    }
    return value;
}

Ship::~Ship(){
    
    delete [] sh_type;
       sh_type = nullptr;
    
}
}
