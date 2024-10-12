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

//对通讯录进行初始化
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示联系人
void ShowContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//清空所有联系人
void QingContact(Contact* pc);

//排序联系人
void PaiContact(Contact* pc);