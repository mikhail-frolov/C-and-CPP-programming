#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <stdio.h>
#include <fstream>
#include <cctype>
#include <iostream>
namespace sdds{

class ReadWritable {

    bool csvflag;
    
public:
    ReadWritable();
    virtual ~ReadWritable(){};
    bool isCsv() const;
    void setCsv(bool value);
    
   virtual std::ostream& write(std::ostream& ostr) const = 0;
   virtual std::istream& read(std::istream& istr) = 0;
};

std::ostream& operator<<(std::ostream& os, const ReadWritable & R);
std::istream& operator>>(std::istream& in, ReadWritable & R);

}

#endif


