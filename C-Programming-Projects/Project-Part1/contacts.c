//==============================================
// Name:           Mikhail Frolov
// Student Number: 164788184
// Email:          mfrolov@myseneca.ca
// Section:        NZB
// Date:           November 10, 2019
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//clears the input buffer
void clearIt(void);

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name){
     char option;
    
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearIt();
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c", &option);
       clearIt();
    switch (option) {
        case 'y':
          printf("Please enter the contact's middle initial(s): ");
            scanf("%6[^\n]",name->middleInitial);
               clearIt();
            break;
            case 'Y':
                     printf("Please enter the contact's middle initial(s): ");
            scanf("%6[^\n]",name->middleInitial);
                          clearIt();
                       break;
        case 'n':
            break;
            case 'N':
                      break;
        default:
            break;
    }
    
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]",name->lastName);
    clearIt();

};


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *address){
    char option;
do {
            printf("Please enter the contact's street number: ");
    scanf("%d",&address->streetNumber);
           clearIt();
} while (address->streetNumber < 1);
   
   printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
   clearIt();

   printf("Do you want to enter an apartment number? (y or n): ");
   scanf("%c", &option);
      clearIt();
   switch (option) {
       case 'y':
          do{
               printf("Please enter the contact's apartment number: ");
              scanf("%d",&address->apartmentNumber);
                        clearIt();
          } while (address->apartmentNumber < 1);
                         break;
           
           case 'Y':
                   do{
                             printf("Please enter the contact's apartment number: ");
                       scanf("%d",&address->apartmentNumber);
                                  clearIt();
                   } while (address->apartmentNumber < 1);
                                   break;
       case 'n':
           break;
           case 'N':
                     break;
       default:
           break;
   }
   printf("Please enter the contact's postal code: ");
   scanf("%7[^\n]",address->postalCode); //[^\n] reads a string with spaces
   clearIt();
   printf("Please enter the contact's city: ");
   scanf("%40[^\n]",address->city); //[^\n] reads a string with spaces
   clearIt();
};


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numbers){
    char option;
    
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c", &option);
    switch (option) {
        case 'y':
                printf("Please enter the contact's cell phone number: ");
                      scanf("%10s",numbers->cell);
            clearIt();
                          break;
            case 'Y':
                printf("Please enter the contact's cell phone number: ");
                              scanf("%10s",numbers->cell);
                    clearIt();
                                  break;
            
        case 'n':
            break;
            case 'N':
                      break;
        default:
            break;
    }
    
    printf("Do you want to enter a home phone number? (y or n): ");
       scanf("%c", &option);
       switch (option) {
           case 'y':
                   printf("Please enter the contact's home phone number: ");
                         scanf("%10s",numbers->home);
               clearIt();
                             break;
               case 'Y':
                   printf("Please enter the contact's home phone number: ");
                                 scanf("%10s",numbers->home);
                       clearIt();
                                     break;
               
           case 'n':
               break;
               case 'N':
                         break;
           default:
               break;
       }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c", &option);
       switch (option) {
           case 'y':
                   printf("Please enter the contact's business phone number: ");
                   scanf("%10s",numbers->business);
                   clearIt();
                             break;
               case 'Y':
                   printf("Please enter the contact's business phone number: ");
                   scanf("%10s",numbers->business);
                   clearIt();
                                     break;
               
           case 'n':
               break;
               case 'N':
                         break;
           default:
               break;
       }
       
    printf("\n");
};


// clearIt empties the input buffer
void clearIt(void)
{
        while (getchar() != '\n')
                ;  // empty statement intentional
}
