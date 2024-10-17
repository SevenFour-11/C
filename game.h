#pragma once 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#define NAME_MAX 20 
#define SEX_MAX 5 
#define TELE_MAX 12 
#define ADDR_MAX 30 
#define MAX 100 
typedef struct PeoInfo 
{
	char name[NAME_MAX]; 
	int age; 
	char sex[SEX_MAX];
	char tele[TELE_MAX]; 
	char addr[ADDR_MAX];
} PeoInfo;
typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
} Contact;

void InitContact(Contact* pc);
void AddContact(Contact* pc);
void ShowContact(Contact* pc);
void DelContact(Contact* pc);
void SearchContact(Contact* pc);
void ModifyContact(Contact* pc);
void QingContact(Contact* pc);
void PaiContact(Contact* pc);
void SaveContactsToFile(Contact* pc, const char* filename);
void LoadContactsFromFile(Contact* pc, const char* filename);
