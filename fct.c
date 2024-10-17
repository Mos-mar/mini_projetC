#include "fct.h"

void addContact(char* contactName, char* contactNum) //verification si il existe déjà
{
  printf("Enter Name size : ");
  int namesize;
  scanf ("%d" ,&namesize);
  
  printf("Enter Number size : ");
  int nbsize;
  scanf ("%d" ,&nbsize);

  char addName[namesize ], addNum[nbsize ];
  printf("Enter your Name: ");
  scanf("%s", addName);

  printf("Enter your Number: ");
  scanf("%s", addNum);

  int i = 0;
  while (contactName[i] != '\0') i++;
  
  strcpy(contactName + i, addName);
  strcat(contactName + i, " "); // ajout espace separateur
  strcpy(contactNum + i, addNum);
  strcat(contactNum + i, " "); //  ajout espace separateur
}

void getContact(char* contactName, char* contactNum)
{
  printf("Enter Name or Num you want to search : ");
  char item[50];
  scanf("%s",item);

  for(int i = 0 ; i < ARRAY_SIZE ; i++)
  {
    if(isalpha(item[0]))
    {
      if(strstr(contactName + i , item) )
      {
        int indexName = strstr(contactName, item) - contactName;
        printf("Contacts exists, getContact: %s, %s\n", contactName + indexName, contactNum + indexName);
        break;
      }else {
        printf("Contact doesn't exist\n");
        break;
      }
    }else if(isdigit(item[0]))
     {
       if(strstr(contactNum + i , item) )
       {
        int indexNum = strstr(contactNum, item) - contactNum;
        printf("Contacts exists, getContact: %s, %s\n", contactName + indexNum, contactNum + indexNum);
        break;
        }else {
        printf("Contact doesn't exist\n");
        break;
        } 
     }
  }
  
}

void getAllContacts(char* contactName, char* contactNum) {
    int nameIndex = 0;
    int numIndex = 0;

    while (contactName[nameIndex] != '\0' && contactNum[numIndex] != '\0') {
        int nameEnd = nameIndex;
        while (contactName[nameEnd] != ' ' && contactName[nameEnd] != '\0') {
            nameEnd++;
        }

        int numEnd = numIndex;
        while (contactNum[numEnd] != ' ' && contactNum[numEnd] != '\0') {
            numEnd++;
        }

        printf("Name: ");
        for (int i = nameIndex; i < nameEnd; i++) {
            printf("%c", contactName[i]);
        }
        printf(", Number: ");
        for (int i = numIndex; i < numEnd; i++) {
            printf("%c", contactNum[i]);
        }
        printf("\n");

        nameIndex = nameEnd + 1;  // saut au prochain ' '
        numIndex = numEnd + 1;    
    }
}


void popContact()
{

}
