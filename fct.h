#ifndef FCT_H
#define FCT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ARRAY_SIZE 100
void addContact(char* contactName, char* contactNum); //verification si il existe déjà
void getContact(char* contactName, char* contactNum);
void getAllContacts(char* contactName, char* contactNum);
void popContact();

#endif // fct_HPP