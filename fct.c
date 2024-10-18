#include "fct.h"

void addContact(Contacts* c)
{
    //Trouver la fin des chaînes existantes
    int nameIndex = strlen(c->Names);
    int numIndex = strlen(c->Numbers);

    char tempName[50], tempNum[50];

    printf("Enter your Name: ");
    scanf(" %[^\n]", tempName);
    getchar();

    printf("Enter your Number: ");
    scanf(" %[^\n]", tempNum);
    getchar();

    //Ajouter le nouveau contact à la fin des chaînes existantes
    strcat(c->Names + nameIndex, tempName);
    strcat(c->Names + nameIndex, "|");
    strcat(c->Numbers + numIndex, tempNum);
    strcat(c->Numbers+ numIndex, "|");
}

void getContact(Contacts* c)
{
    printf("Enter Name or Num you want to search : ");
    char item[50];
    scanf("%s", item);

    int nameIndex = 0;
    int numIndex = 0;
    bool found = false; 

    while (c->Names[nameIndex] != '\0' && c->Numbers[numIndex] != '\0') 
    {
        //Trouver la fin du nom et du numéro actuels
        int nameEnd = nameIndex;
        int numEnd = numIndex;
        while (c->Names[nameEnd] != '|' && c->Names[nameEnd] != '\0') nameEnd++; //On incrémente au prochain char du string jusquu'a la fin du mot marqué par | ou EOF
        while (c->Numbers[numEnd] != '|' && c->Numbers[numEnd] != '\0') numEnd++; //On incrémente au prochain char du string jusquu'a la fin du mot marqué par | ou EOF

        // Vérifier si l'item correspond au nom ou au numéro actuels
        if ((isalpha(item[0]) && strncmp(c->Names + nameIndex, item, strlen(item)) == 0) || (isdigit(item[0]) && strncmp(c->Numbers + numIndex, item, strlen(item)) == 0)) 
        {
            printf("Contact exists: %.*s %.*s\n",nameEnd - nameIndex, c->Names + nameIndex,numEnd - numIndex, c->Numbers + numIndex); //%.*s print le nombre de char précisé par End - Index
            found = true;
            break;
        }

        //Passer au contact suivant
        nameIndex = nameEnd + 1;
        numIndex = numEnd + 1;
    }

    if (!found) printf("Contact doesn't exist\n");
    
}

void getAllContacts(Contacts* c) {
    int nameIndex = 0;
    int numIndex = 0;

    while (c->Names[nameIndex] != '\0' && c->Numbers[numIndex] != '\0') 
    {
        int nameEnd = nameIndex;
        while (c->Names[nameEnd] != '|' && c->Names[nameEnd] != '\0') 
        {
            nameEnd++;
        }

        int numEnd = numIndex;
        while (c->Numbers[numEnd] != '|' && c->Numbers[numEnd] != '\0') 
        {
            numEnd++;
        }

        printf("Name: ");
        for (int i = nameIndex; i < nameEnd; i++) 
        {
            printf("%c", c->Names[i]);
        }

        printf(", Number: ");
        for (int i = numIndex; i < numEnd; i++) 
        {
            printf("%c", c->Numbers[i]);
        }
        printf("\n");

        // saut au prochain string
        nameIndex = nameEnd + 1;  
        numIndex = numEnd + 1;    
    }
}


void popContact(Contacts* c)
{
    char eraseName[50], eraseNum[50];
    printf("Enter name to erase : ");
    scanf(" %[^\n]", eraseName);
    getchar();
    printf("Enter number to erase : ");
    scanf(" %[^\n]", eraseNum);
    getchar();

    char* nameStart = c->Names;
    char* numStart = c->Numbers;
    bool found = false;

    while (*nameStart != '\0' && *numStart != '\0')
    {
        char* nameEnd = strchr(nameStart, '|');
        char* numEnd = strchr(numStart, '|');

        if (nameEnd == NULL || numEnd == NULL) break; //notre \0 perso

        int nameLen = nameEnd - nameStart;
        int numLen = numEnd - numStart;

        if (strncmp(nameStart, eraseName, nameLen) == 0 && strncmp(numStart, eraseNum, numLen) == 0)
        {
            // Contact trouvé, on le supprime
            memmove(nameStart, nameEnd + 1, strlen(nameEnd));
            memmove(numStart, numEnd + 1, strlen(numEnd));
            found = true;
            break;
        }

        nameStart = nameEnd + 1;
        numStart = numEnd + 1;
    }

    if (found) printf("Contact successfully deleted.\n");
    else printf("Contact not found.\n"); 
}


