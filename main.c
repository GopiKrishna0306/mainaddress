/*Name:Natham Gopi Krishna Reddy
project name:address book.
1.create contact
2.search contatct
3.edit contact
4.delete contact
5.list all contacts
6.save and exit.*/
#include <stdio.h>
#include "contact.h"


int main() 
{
    int choice;
    AddressBook addressBook;
    addressBook.contactCount = 0;
    loadContactsFromFile(&addressBook);

    do {
    printf("\nAddress Book Menu:\n");
    printf("1. 🖋️   Create contact\n");
    printf("2. 🔍  Search contact\n");
    printf("3. 📝  Edit contact\n");
    printf("4. 🚮  Delete contact\n");
    printf("5. 📄  List all contacts\n");
    printf("6. 🖐️   Save contacts and exit\n");		
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        // input was not a number
        printf("Invalid input. Please enter a number (1-6).\n");
        while (getchar() != '\n'); // flush bad input
        continue; // restart loop
    }
    while (getchar() != '\n');  // flush leftover newline

    switch (choice) {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            searchContactAndSelect(&addressBook);
            break;
        case 3:
            editContact(&addressBook);
            break;
        case 4:
            deleteContact(&addressBook);
            break;
        case 5:          
            listContacts(&addressBook);
            break;
        case 6:
            printf("Saving and Exiting...🖐️🖐️\n");
            saveContactsToFile(&addressBook);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != '6');


return 0;
}

