#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cctype>
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

