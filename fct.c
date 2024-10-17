#include "fct.h"

void addContact(char* contactName, char* contactNum)
{
    //Trouver la fin des chaînes existantes
    int nameIndex = strlen(contactName);
    int numIndex = strlen(contactNum);

    char tempName[50], tempNum[50];

    printf("Enter your Name: ");
    scanf(" %[^\n]", tempName);
    getchar();

    printf("Enter your Number: ");
    scanf(" %[^\n]", tempNum);
    getchar();

    //Ajouter le nouveau contact à la fin des chaînes existantes
    strcat(contactName + nameIndex, tempName);
    strcat(contactName + nameIndex, "|");
    strcat(contactNum + numIndex, tempNum);
    strcat(contactNum + numIndex, "|");
}

void getContact(char* contactName, char* contactNum)
{
    printf("Enter Name or Num you want to search : ");
    char item[50];
    scanf("%s", item);

    int nameIndex = 0;
    int numIndex = 0;
    bool found = false;

    while (contactName[nameIndex] != '\0' && contactNum[numIndex] != '\0') 
    {
        //Trouver la fin du nom et du numéro actuels
        int nameEnd = nameIndex;
        int numEnd = numIndex;
        while (contactName[nameEnd] != '|' && contactName[nameEnd] != '\0') nameEnd++; //On incrémente au prochain char du string jusquu'a la fin du mot marqué par | ou EOF
        while (contactNum[numEnd] != '|' && contactNum[numEnd] != '\0') numEnd++; //On incrémente au prochain char du string jusquu'a la fin du mot marqué par | ou EOF

        // Vérifier si l'item correspond au nom ou au numéro actuels
        if ((isalpha(item[0]) && strncmp(contactName + nameIndex, item, strlen(item)) == 0) || (isdigit(item[0]) && strncmp(contactNum + numIndex, item, strlen(item)) == 0)) 
        {
            printf("Contact exists: %.*s %.*s\n",nameEnd - nameIndex, contactName + nameIndex,numEnd - numIndex, contactNum + numIndex); //%.*s print le nombre de char précisé par End - Index
            found = true;
            break;
        }

        //Passer au contact suivant
        nameIndex = nameEnd + 1;
        numIndex = numEnd + 1;
    }

    if (!found) printf("Contact doesn't exist\n");
    
}

void getAllContacts(char* contactName, char* contactNum) {
    int nameIndex = 0;
    int numIndex = 0;

    while (contactName[nameIndex] != '\0' && contactNum[numIndex] != '\0') 
    {
        int nameEnd = nameIndex;
        while (contactName[nameEnd] != '|' && contactName[nameEnd] != '\0') 
        {
            nameEnd++;
        }

        int numEnd = numIndex;
        while (contactNum[numEnd] != '|' && contactNum[numEnd] != '\0') 
        {
            numEnd++;
        }

        printf("Name: ");
        for (int i = nameIndex; i < nameEnd; i++) 
        {
            printf("%c", contactName[i]);
        }

        printf(", Number: ");
        for (int i = numIndex; i < numEnd; i++) 
        {
            printf("%c", contactNum[i]);
        }
        printf("\n");

        // saut au prochain '|'
        nameIndex = nameEnd + 1;  
        numIndex = numEnd + 1;    
    }
}


void popContact()
{

}
