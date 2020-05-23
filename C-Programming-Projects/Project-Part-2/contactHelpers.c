//==============================================
// Name:           Mikhail Frolov
// Student Number: 164788184
// Email:          mfrolov@myseneca.ca
// Section:        NZB
// Date:           November 21th, 2019
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"
#define MAXCONTACTS 5
#include <ctype.h>

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
    while (getchar() != '\n')
        ; // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pauseit(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
    int value = 0;
    char NL;
    NL = 'x';
    
    while (NL != '\n') {
        scanf("%d%c",&value, &NL);
        
        if (NL!= '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
    int integer;
    do {
        integer = getInt();
        if (integer > max || integer < min) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",min, max);
        }
    } while (integer > max || integer < min);
    return integer;
}

// yes: Empty function definition goes here:
int yes(void)
{
   char choice = '\0' , NL = 'x';
     
    scanf("%c%c", &choice, &NL);
    if(NL != '\n')
      {
          clearKeyboard();
      }
    
    while((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')|| NL != '\n') {
        
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf("%c%c", &choice, &NL);
        
        if(NL != '\n')
        {
            clearKeyboard();
        }
    }
 return((choice=='y') || (choice=='Y')) ? 1 : 0;
}
    

// menu: Empty function definition goes here:
int menu(void)
{
    int menu;
    
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    
    menu = getIntInRange(0,6);
    printf("\n");
    return menu;
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
        struct Contact contacts[MAXCONTACTS] =
     { { { "Rick",{ '\0' }, "Grimes" },
       { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
       { "4161112222", "4162223333", "4163334444" } },
    {
       { "Maggie", "R.", "Greene" },
       { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
       { "9051112222", "9052223333", "9053334444" } },
    {
       { "Morgan", "A.", "Jones" },
       { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
       { "7051112222", "7052223333", "7053334444" } },
    {
       { "Sasha",{ '\0' }, "Williams" },
       { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
       { "9052223333", "9052223333", "9054445555" } },
};
    
    int selection;
    int choice = 0;
    
    while(choice == 0){
          selection = menu();
    switch (selection) {
        case 1:
            displayContacts(contacts,MAXCONTACTS);
            pauseit();
            printf("\n");
            break;
        
        case 2:
            addContact(contacts,MAXCONTACTS);
            pauseit();
            printf("\n");
            break;
            
        case 3:
            updateContact(contacts, MAXCONTACTS);
            pauseit();
            printf("\n");
            break;
            
        case 4:
            deleteContact(contacts, MAXCONTACTS);
            pauseit();
            printf("\n");
            break;
            
        case 5:
            searchContacts(contacts, MAXCONTACTS);
            pauseit();
            printf("\n");
            break;
            
        case 6:
            sortContacts(contacts, MAXCONTACTS);
            pauseit();
            printf("\n");
            break;
            
        case 0:
            printf("Exit the program? (Y)es/(N)o: ");
            choice = yes();
            printf("\n");
            break;
            
        default:
            break;
    }
}
    printf("Contact Management System: terminated\n");
}
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------

    void getTenDigitPhone(char phoneNum[]) {
        int answ;
        int notcorrect = 0;
        scanf("%s", phoneNum);
        clearKeyboard();
        while(strlen(phoneNum)!=10) {
            printf("Enter a 10-digit phone number: ");
            scanf("%s", phoneNum);
            clearKeyboard();
        }
        int i;
        for ( i = 0 ; i < strlen(phoneNum) ; i++){
            notcorrect = 0;
            answ = isdigit(phoneNum[i]);
            if (answ ==0) {
                notcorrect = 1;
            }
    if (notcorrect==1) {
        printf("Enter a 10-digit phone number: ");
        scanf("%s", phoneNum);
        clearKeyboard();
    }
        }
    }
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    for (i=0; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell,cellNum) == 0) {
            return i;
        }
            }
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");    printf("Total contacts: %d\n\n",count);
}



// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact)
{
    printf(" %s",  contact->name.firstName);
    if (strlen(contact->name.middleInitial) != 0) {
        printf(" %s %s\n", contact->name.middleInitial , contact->name.lastName);
    } else {
        printf(" %s\n", contact->name.lastName);
    }
        printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
        printf("       %d %s, ",contact->address.streetNumber, contact->address.street);
        if (contact->address.apartmentNumber > 0) {
            printf("Apt# %d, ", contact->address.apartmentNumber);
            printf("%s, %s\n", contact->address.city, contact->address.postalCode);
        } else{
            printf("%s, %s\n", contact->address.city, contact->address.postalCode);
        }
    }


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i;
    int count = 0;
    displayContactHeader();
    
    for (i=0; i < size; i++) {
        
        if (strlen(contacts[i].numbers.cell) != 0) {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}



// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    int index;
    char number[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(number);
    index = findContactIndex(contacts, size, number);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        {
            if (strlen(contacts[i].numbers.cell) == 0) {
                break;
            }
        }
    if (i == size) {
        printf("*** ERROR: The contact list is full! ***\n\n");
    } else {
            getContact(&contacts[i]);
            printf("--- New contact added! ---\n\n");
        }
    }


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    int option;
    int index;
    char number[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(number);
    index = findContactIndex(contacts, size, number);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        option=yes();
        if (option == 1) {
            *contacts[index].name.firstName = '\0';
            *contacts[index].name.lastName = '\0';
            *contacts[index].name.middleInitial = '\0';
            getName(&contacts[index].name);
        }
   printf("Do you want to update the address? (y or n): ");
        option=yes();
        if (option == 1) {
            getAddress(&contacts[index].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        option=yes();
        if (option == 1) {
            *contacts[index].numbers.cell = '\0';
            *contacts[index].numbers.home = '\0';
            *contacts[index].numbers.business = '\0';
            getNumbers(&contacts[index].numbers);
        }
        printf("--- Contact Updated! ---\n\n");
    }
    }


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    int option;
    int index;
    char number[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(number);
    index = findContactIndex(contacts, size, number);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n");
    } else {
        printf("\nContact found:\n");
    displayContact(&contacts[index]);
           printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        option=yes();
        if (option == 1) {
            contacts[index].numbers.home[0] = '\0';
            contacts[index].numbers.business[0] = '\0';           
            contacts[index].numbers.cell[0]= '\0';
            printf("--- Contact deleted! ---\n\n");
        }else{
            printf("\n");
        }
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
    int i;
    int j;
        struct Contact sort;
        for (i = 0; i < size-1; i++)
        {
            for (j = i+1; j  < size; j ++)
            {
                if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0) {
                    if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) {
                        sort = contacts[i];
                        contacts[i] = contacts[j];
                        contacts[j] = sort;
                    }
                }
            }
        }
        printf("--- Contacts sorted! ---\n\n");
    }
