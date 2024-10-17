#include "fct.h"

int main()
{
    char name[ARRAY_SIZE];
    char numbers[ARRAY_SIZE];

    //while pour choisir les fcts.
    while(true)
    {
        printf("Enter 1 to addContact, 2 to getContact, 3 to getAllContacts, 4 to popContact, 5 to exit : " );
        int choice = 0;
        scanf("%d",&choice);
        switch (choice) 
        {
            case 1:
                addContact(name, numbers);
                continue;
            case 2:
                getContact(name, numbers);
                continue;
            case 3:
                getAllContacts(name, numbers);
                continue;
            case 4:
                popContact(name, numbers);
                continue;
            case 5:
               exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
    return 0;
}
