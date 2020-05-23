/* ------------------------------------------------------
Final Project Milestone 3
Module: ReadWritable
Filename: ms3_RWTester.cpp
Version 1.0
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date March 25th, 2020     Name: Mikhail Frolov
2020/3/23  Preliminary release
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "ReadWritable.h"
using namespace std;
namespace sdds{

ReadWritable::ReadWritable(){
    csvflag = false;
}

bool ReadWritable::isCsv() const{
    return csvflag;
}

void ReadWritable::setCsv(bool value){
    csvflag = value;
}

ostream& operator<<(ostream& os, const ReadWritable & R){
    R.write(os);
    return os;
}

istream& operator>>(istream& in, ReadWritable & R){
    R.read(in);
    return in;
}

}
