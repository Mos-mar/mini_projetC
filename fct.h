#ifndef FCT_H
#define FCT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> //isalpha et isdigit "abc" ou "123"

#define ARRAY_SIZE 100
typedef struct  Contacts
{
    char Names[ARRAY_SIZE];
    char Numbers[ARRAY_SIZE];
}Contacts;

void addContact(Contacts* c); //verification si il existe déjà
void getContact(Contacts* c);
void getAllContacts(Contacts* c);
void popContact();

#endif // fct_HPP