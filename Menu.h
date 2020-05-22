/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/2  Preliminary release
-----------------------------------------------------------*/
// Name  Mikhail Frolov     Date March 12,2020
/////////////////////////////////////////////////////////////////

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <stdio.h>
#include <iostream>
namespace sdds{

 const int MAX_NO_OF_ITEMS = 10;

  
class Menuitem {
    
    char* name;
    
    Menuitem();
    Menuitem(const char*);
    ~Menuitem();
    // cannot get copied or assigned
    Menuitem(const Menuitem& x) = delete;
    Menuitem& operator=(const Menuitem& x) = delete;
    friend class Menu;
    
};

class Menu {
    
    char * title;
    Menuitem* item;
    
    int indentation = 0;
    int count = 0;

public:
    
    Menu();
    Menu(const Menu&);
    Menu(const char* , int = 0 );
    ~Menu();
    
    bool isEmpty() const;
    operator bool() const;
    operator int() const;
    Menu& operator<<(const char*);
    Menu& operator=(const Menu& menu);
    Menu& operator=(const char*);
    void add(const char*);
    int run() const;
    void display() const;
    
};
}
#endif  
