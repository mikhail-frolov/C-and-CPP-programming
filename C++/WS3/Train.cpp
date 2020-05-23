/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.cpp
// Version 1.0
// Date    2020/01/19
// Author Michael Huang
// Description
// Tests Train module
//
// Revision History
// -----------------------------------------------------------
// Name  Mikhail Frolov          Date January 31 2020            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <string>
#include <cctype>
#include <iostream>
#include "Train.h"

using namespace std;
namespace sdds{

void Cargo::init(const char* ddesc, double wweight){
       
    if (strlen(ddesc) < MAX_DESC){
        
            strcpy(description, ddesc);
    }
             if (wweight < MIN_WEIGHT || wweight > MAX_WEIGHT) {
                 setWeight(MIN_WEIGHT);
             } else {
              setWeight(wweight);
         }
}

char* Cargo::getDesc(){
    return description;
}

double Cargo::getWeight(){
    return weight;
}

void Cargo::setWeight(double weightt){
    weight = weightt;
}


void Train::setTrain(const char* pname, int idd){

    if (pname == nullptr || idd < 1 || pname[0] == '\0'){
        name[0] = '\0';
        id = 0;
        
    } else {
        strcpy(name, pname);
        id = idd;
    }
    cargo = nullptr;
}

bool Train::isEmpty() const{
    bool value ;
    if (id >= 1 || name[0] != '\0' || strlen(name) != 0) {
        value = false;
    } else {
        value = true;
    }
    return value;
}

void Cargo::setDesc(char* newcargo){
    strcpy(description, newcargo);
}

bool Train::increaseCargo(double increase){
    bool success = false;
    //double add = 0.0;
    
    if (cargo != nullptr){
        if (cargo->getWeight() < MAX_WEIGHT) {
      double sum =  increase + cargo->getWeight();
       if (sum > MAX_WEIGHT) {
                 cargo->setWeight(MAX_WEIGHT);
           success = true;
       } else if (sum < MAX_WEIGHT){
           cargo->setWeight(sum);
           success = true;
       }
    }
    }
    return success;
}


bool Train::decreaseCargo(double decrease){
    bool success = false;
    
    if (cargo != nullptr){
        if (cargo->getWeight() > MIN_WEIGHT){
            double minus = cargo->getWeight() - decrease;

             if (minus > MAX_WEIGHT) {
                 cargo->setWeight(MAX_WEIGHT);
                 success = false;
             } else if (minus < MIN_WEIGHT) {
                 cargo->setWeight(MIN_WEIGHT);
                 success = false;
    } else if (minus > MIN_WEIGHT){
            
            cargo->setWeight(minus);
                 success = true;
    }
    }
    }
    return success;
}

void Train::display() const{
    
    cout << "***Train Summary***" << endl;
    if (isEmpty() == true) {
      cout << "This is an empty train." << endl;
    } else {
        cout << "Name: " << name << " ID: " << id << endl;
        
        if(cargo != nullptr) {
            
            cout << "Cargo: " << cargo->getDesc();
            cout.precision(2);
            cout << " Weight: " << fixed << cargo->getWeight() << endl;
        } else {
            cout << "No cargo on this train." << endl;
        }
    }
}

void Train::loadCargo(Cargo cargo1){
   
    cargo = new Cargo;
    strcpy(cargo->getDesc(), cargo1.getDesc());
    cargo->setWeight(cargo1.getWeight());
    
}

void Train::unloadCargo() {
    
    delete cargo;
    cargo = nullptr;
}

bool Train::swapCargo(Train& diffTrain){
    bool success = false;
    
    if (cargo != nullptr && diffTrain.cargo != nullptr) {
        
        Cargo swap;
        
        swap.setDesc(cargo->getDesc());
        swap.setWeight(cargo->getWeight());
        
        cargo->setDesc(diffTrain.cargo->getDesc());
        cargo->setWeight(diffTrain.cargo->getWeight());
        
        diffTrain.cargo->setDesc(swap.getDesc());
        diffTrain.cargo->setWeight(swap.getWeight());
        
       
        success = true;
        
        }
return success;
}
}
