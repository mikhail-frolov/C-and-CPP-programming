/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: Menu.cpp
Version 1.0
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/12  Preliminary release
-----------------------------------------------------------*/
// Name  Mikhail Frolov     Date March 15,2020
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds{

Menuitem::Menuitem() {
        name = nullptr;
    }

Menuitem::Menuitem(const char* Iitem) {
        if (Iitem == nullptr) {
            name = nullptr;
        } else {
            int len = strlen(Iitem) + 1;
            name = new char[len];
              strcpy(name, Iitem);
        }
    }

    Menuitem::~Menuitem(){
        delete[] name;
        name = nullptr;
    }

bool Menu::isEmpty() const {
    
    bool value = false;
    
    if (count == 0) {
        value = true;
    } else {
        //check values for null
        for (int i = 0; i < count; i++) {
           if (item[i].name == nullptr) {
              value = true;
        }
        }
    }
    return value;
}
Menu::Menu() {
    item = new Menuitem[MAX_NO_OF_ITEMS];
    title = nullptr;
    count = 0;
}


Menu::~Menu() {
    delete[] title;
    
    for (int i = 0 ; i < count; i++) {
        item[i].~Menuitem();
    }
    
    delete[] item;
}

Menu::Menu(const char* ttitle, int ind) {
        
        item = new Menuitem[MAX_NO_OF_ITEMS];
        
        if (ttitle == nullptr) {
            title = nullptr;
        } else {
            title = new char[strlen(ttitle)+1];
            strcpy(title, ttitle);
            count = 0;
        }
        if (ind >= 0) {
            indentation = ind;
        }
    }

Menu::Menu(const Menu& menu) {
        //title
         int len = strlen(menu.title) + 1;
        title = new char[len];
        strcpy(title, menu.title);
        //ints
        indentation = menu.indentation;
        count = menu.count;
        //item
        item = new Menuitem[MAX_NO_OF_ITEMS];
        
        for (int i = 0; i < count; i++) {
            
            if (menu.item[i].name == nullptr) {
                item[i].name = nullptr;
            } else {
                int len1 = strlen(menu.item[i].name) + 1;
               item[i].name = new char[len1];
                strcpy(item[i].name, menu.item[i].name);
            }
        }
    }

void Menu::add(const char* iitem) {
        
        if (iitem == nullptr) {
           item[count].name = nullptr;
        } else {
            int len = strlen(iitem) + 1;
            item[count].name = new char[len];
            strcpy(item[count].name, iitem);
        }
        count++;
    }

Menu& Menu::operator<<(const char* optn){
              this->add(optn);
              return *this;
          }

Menu& Menu::operator=(const Menu& Menu) {
                delete[] title;
    
                int len = strlen(Menu.title) + 1;
                title = new char[len];
                strcpy(title, Menu.title);
                indentation = Menu.indentation;

            for (int i = 0; i < count; i++) {
                delete[] item[i].name;
                item[i].name = nullptr;
            }
    
            count = Menu.count;
    
            for (int i = 0; i < count; i++) {
                if (Menu.item[i].name == nullptr) {
                    item[i].name = nullptr;
                } else {
                    int len1 = strlen(Menu.item[i].name) + 1 ;
                    item[i].name = new char[len1];
                    strcpy(item[i].name, Menu.item[i].name);
                }
            }
            return  *this;
        }

Menu& Menu::operator=(const char* Ttitle) {
            delete[] title;
            
            int len = strlen(Ttitle) + 1;
            title = new char[len];
            strcpy(title, Ttitle);
            
            return *this;
        }

Menu::operator bool() const {
            
            bool result = true;
            
            if (this->isEmpty()) {
                result = false;
            }
            return result;
        }

Menu::operator int() const {
            return this->run();
        }

        
int Menu::run() const {
    int x = 0;
    if (this->isEmpty()) {
                this->display();
                x = 0;
            } else {
                int optn;
                int validation;
                
                this->display();
                cin >> optn;
                
                while (!cin.good() || optn < 1 || optn > count) {
                    
                    if (cin.good()){
                        validation = 1;
                    } else {
                        validation = 0;
                    }
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    
                    if (!validation){
                        cout << "Invalid Integer, try again: ";
                    } else {
                        cout << "Invalid selection, try again: ";
                    }
                    cin >> optn;
                }
                cin.clear();
                cin.ignore(1000, '\n');
                x = optn;
            }
    return x;
        }

void Menu::display() const {
   
           int nullvalue = 0;
   
         for (int i = 0; i < count; i++){
          
             if (item[i].name == nullptr){
                   nullvalue++;
           }
         }
           if (nullvalue == count){
               
               cout << setfill(' ') << setw(indentation * 4 + strlen(title));
               cout << title << endl;
               cout << "No Items to display!" << endl;
           
           } else if (nullvalue > 0 && nullvalue < count) {

               cout << "Invalid Menu!" << endl;
           
           } else {
               
               cout << setfill(' ') << setw(indentation * 4 + strlen(title));
               cout << title << endl;
               
               for (int i = 0; i < count; i++){
                   
                   cout << setfill(' ') << setw(indentation*4+1);
                   cout << i + 1 << "- " << item[i].name << endl; }
                   cout << setfill(' ') << setw(indentation * 4);
                   cout << "" << "> ";
           }
       }
}
