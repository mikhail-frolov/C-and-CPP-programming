/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading
// File Gift.cpp
// Version 1.0
// Date    2020/01/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
// Revision History
// -----------------------------------------------------------
// Name   Mikhail Frolov         Date  January 27, 2020           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include "Gift.h"

using namespace std;
namespace sdds {

//stores description
void gifting(char* desc){

    cout << "Enter gift description: ";
    cin.width(MAX_DESC + 1);
    cin >> desc;
    
};

//stores the price
void gifting(double& price){

  cout << "Enter gift price: ";
    cin >> price;

    while (price < 0 || MAX_PRICE < price) {
        cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
        cout << "Enter gift price: ";
        cin >> price;
    };
};

//stores the amount of units
void gifting(int& g){

    cout << "Enter gift units: ";
    cin >> g;
    
    while (g < 1) {
        cout << "Gift units must be at least 1" << endl;
        cout << "Enter gift units: ";
        cin >> g;
    };
}

void gifting(Gift& prep){
    cout << "Preparing a gift..." << endl;
    gifting(prep.g_description);
    gifting(prep.g_price);
    gifting(prep.g_units);
    wrap(prep);
}


//displays gift details
void display(const Gift& gift){
    

    cout << "Gift Details:" << endl;
    cout << "Description: " << gift.g_description  << endl;
    cout << "Price: " << gift.g_price << endl;
    cout << "Units: " << gift.g_units << endl;
    
    if (gift.wrap_layers == 0) {
        cout << "Unwrapped" << endl;
    } else {
        cout << "Wrap Layers: " << gift.wrap_layers << endl;
        for(int i = 0; i < gift.wrap_layers; i++){
            cout << "Wrap #" << (i+1) << ": " << gift.wrap[i].pattern << endl;
    }
}
}

bool wrap(Gift& gftwrap){
    int value;
    
    if (gftwrap.wrap_layers == 0) {
        cout << "Wrapping gifts..." << endl;
        cout << "Enter the number of wrapping layers for the Gift: ";
        cin >> gftwrap.wrap_layers;
        while (gftwrap.wrap_layers <= 0) {
            cout << "Layers at minimum must be 1, try again." << endl;
            cout << "Enter the number of wrapping layers for the Gift: ";
            cin >> gftwrap.wrap_layers;
        }
        
        gftwrap.wrap = new Wrapping[gftwrap.wrap_layers];
        for (int i = 0; i < gftwrap.wrap_layers; i++) {
            char pattern1[MAX_LENGTH];
            
            cout << "Enter wrapping pattern #" << i+1 << ": ";
            cin.width(MAX_LENGTH + 1);
            cin >> pattern1;
            gftwrap.wrap[i].pattern = new char[strlen(pattern1) + 1];
            strcpy(gftwrap.wrap[i].pattern, pattern1);
        }
        value = 1;
    } else {
        cout << "Gift is already wrapped!" << endl;
        value = 0;
    }
    return value;
}

bool unwrap(Gift& gftwrap){
    int value;
    if (gftwrap.wrap_layers != 0) {
       cout << "Gift being unwrapped." << endl;
        delete [] gftwrap.wrap;
        gftwrap.wrap = nullptr;
        gftwrap.wrap_layers = 0;
        
        value = 1;
    } else {
       cout << "Gift isn't wrapped! Can't unwrap." << endl;
        value = 0;
    }
    return value;
}

}
