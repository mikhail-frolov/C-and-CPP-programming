/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.h
// Version 1.0
// Date    2020/01/19
// Author Michael Huang
// Description
// Tests Train module
//
// Revision History
// -----------------------------------------------------------
// Name  Mikhail Frolov          Date January 29th 2020            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TRAIN_H__
#define SDDS_TRAIN_H__

namespace sdds{

const int MAX_NAME = 30;
const int MAX_DESC = 20;
const double MAX_WEIGHT = 700.555;
const double MIN_WEIGHT = 40.444;

class Cargo {
  
    char description[MAX_DESC + 1];
    double weight;

public:
    char* getDesc();
    double getWeight();
    void setWeight(double);
    void setDesc(char*);
    void init(const char*, double);
};

class Train {
  
    char name[MAX_NAME + 1];
    int id;
    Cargo* cargo;
    
public:
    bool increaseCargo(double);
    bool swapCargo(Train&);
    void setTrain(const char*, int);
    bool isEmpty() const;
    void display() const;
    void loadCargo(Cargo);
    void unloadCargo();
    bool decreaseCargo(double);
    
   
};

}
#endif /* Train_h */
