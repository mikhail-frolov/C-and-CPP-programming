//==============================================
// Name:           Mikhail Frolov
// Student Number: 164788184
// Email:          mfrolov@myseneca.ca
// Section:        NZB
// Date:           November 21th, 2019
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:

#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name *name){
     int option;
    
    printf("Please enter the contact's first name: ");
    scanf("%[^\n]", name->firstName);
    clearKeyboard();
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    option = yes();
    if(option == 1) {
        
        printf("Please enter the contact's middle initial(s): ");
            scanf("%6[^\n]",name->middleInitial);
               clearKeyboard();
    }
    
    printf("Please enter the contact's last name: ");
    scanf("%[^\n]",name->lastName);
  clearKeyboard();
};

// getAddress:
void getAddress(struct Address *address){
    int option;
    int number;
    
    printf("Please enter the contact's street number: ");
    number = getInt();
   if (number > 0) {
   address->streetNumber = number;
       
   } else {
       printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
       scanf("%d",&address->streetNumber);
       clearKeyboard();
   }

   printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

   printf("Do you want to enter an apartment number? (y or n): ");
    option = yes();
    if (option == 1) {
        printf("Please enter the contact's apartment number: ");
        number = getInt();
        
         
              if(number > 0){
       address->apartmentNumber=number;
             
              } else {
                  printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                   scanf("%d",&address->apartmentNumber);
                  clearKeyboard();
              }
          
   }
    
   printf("Please enter the contact's postal code: ");
   scanf("%7[^\n]",address->postalCode); //[^\n] reads a string with spaces
  clearKeyboard();
   printf("Please enter the contact's city: ");
   scanf("%40[^\n]",address->city); //[^\n] reads a string with spaces
   clearKeyboard();
};

// getNumbers:
void getNumbers(struct Numbers *numbers){
    int option ;
    
            printf("Please enter the contact's cell phone number: ");
          getTenDigitPhone(numbers->cell);
    
    printf("Do you want to enter a home phone number? (y or n): ");
    option = yes();
    if(option == 1) {
           
           printf("Please enter the contact's home phone number: ");
                         getTenDigitPhone(numbers->home);
       }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    option = yes();
    if(option == 1) {
           
        printf("Please enter the contact's business phone number: ");
                 getTenDigitPhone(numbers->business);
       }
};
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// +-------------------------------------------------+

// getContact
void getContact(struct Contact *contact)
{
    //values get stored in struct Contact. Pointer contact calls values to the appropriate member
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

