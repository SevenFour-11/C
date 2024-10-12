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
	char name[FILENAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;


typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
}Contact;

//��ͨѶ¼���г�ʼ��
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ʾ��ϵ��
void ShowContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

//���������ϵ��
void QingContact(Contact* pc);

//������ϵ��
void PaiContact(Contact* pc);