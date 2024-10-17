#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitContact(Contact* pc) 
{
    assert(pc);
    pc->sz = 0;
    memset(pc->data, 0, sizeof(pc->data));
}
void AddContact(Contact* pc)
{
    assert(pc);
    if (pc->sz == MAX)
    {
        printf("Address book is full, unable to add more.\n");
        return;
    } 
    else
    {
        printf("Please enter the name：");
        scanf("%s", pc->data[pc->sz].name);
        printf("Please enter the age：");
        scanf("%d", &(pc->data[pc->sz].age));
        printf("Please enter the gender：");
        scanf("%s", pc->data[pc->sz].sex);
        printf("Please enter the phone number：");
        scanf("%s", pc->data[pc->sz].tele);
        printf("Please enter the address：");
        scanf("%s", pc->data[pc->sz].addr);
        pc->sz++;
        printf("Increase successful.\n");
    }
}
void ShowContact(Contact* pc)
{
    assert(pc);
    if (pc->sz == 0)
    {
        printf("Address book is empty, no need to print.\n");
        return;
    }
    int i = 0;
    printf("%-20s%-5s%-5s%-12s%-30s%\n", "name", "age", "gender", "phone number", "address");
    for (i = 0; i < pc->sz; i++)
    {
        printf("%-20s%-5d%-5s%-12s%-30s%\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
    }
}
static int FindByName(Contact* pc, char name[])
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->sz; i++)
    {
        if (strcmp(pc->data[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}
void DelContact(Contact* pc)
{
    char name[NAME_MAX];
    assert(pc);
    if (pc->sz == 0)
    {
        printf("The address book is empty, nothing to delete.\n");
        return;
    }
    printf("Please enter the name of the person to be deleted：");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
    {
        printf("The person to be deleted does not exist.\n");
        return;
    }
    int i = 0;
    for (i = ret; i < pc->sz - 1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->sz--;
    printf("Deletion successful.\n");
}
void SearchContact(Contact* pc)
{
    char name[NAME_MAX];
    assert(pc);
    printf("Please enter the name of the person you are looking for：");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
    {
        printf("The person you are looking for does not exist.\n");
        return;
    }
    printf("%-20s%-5s%-5s%-12s%-30s%\n", "name", "age", "gender", "phone number", "address");
    printf("%-20s%-5d%-5s%-12s%-30s%\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}
void ModifyContact(Contact* pc)
{
    int sign = 1;
    char name[NAME_MAX];
    assert(pc);
    printf("Please enter the name of the person you wish to modify：");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
    {
        printf("The person you wish to modify does not exist.\n");
        return;
    }
    while (sign) {
        printf("The data you want to change is:\n");
        printf("1.name                                2.age\n");
        printf("3.gender                              4.phone number\n");
        printf("5.address                             0.close\n");
        scanf("%d", &sign);
        if (sign == 1) {
            printf("Please enter the name：");
            scanf("%s", pc->data[ret].name);
            continue;
        }
        else if (sign == 2) {
            printf("Please enter the age：");
            scanf("%d", &(pc->data[pc->sz].age));
            continue;
        }
        else if (sign == 3) {
            printf("Please enter the gender：");
            scanf("%s", pc->data[ret].sex);
            continue;
        }
        else if (sign == 4) {
            printf("Please enter the phone number：");
            scanf("%s", pc->data[ret].tele);
            continue;
        }
        else if (sign == 5) {
            printf("Please enter the address：");
            scanf("%s", pc->data[ret].addr);
            continue;
        }
        else if (sign == 0) {
            break;
        }
        else {
            printf("Input Error");
            continue;
        }
    }
    printf("Modification Successful\n");
}
void QingContact(Contact* pc)
{
    char name[NAME_MAX];
    assert(pc);
    if (pc->sz == 0)
    {
        printf("The contact list is empty, deletion is not possible.\n");
        return;
    }
    pc->sz = 0;
    memset(pc->data, 0, sizeof(pc->data));
    printf("Deletion Successful.\n");

}
int cmp_s(const void* elem1, const void* elem2)
{
    return strcmp((char*)elem1, (char*)elem2);
}
void PaiContact(Contact* pc)
{
    assert(pc);
    qsort(pc, pc->sz, sizeof(pc->data[0]), cmp_s);
    int i = 0;
    printf("%-20s%-5s%-5s%-12s%-30s%\n", "name", "age", "gender", "phone number", "address");
    for (i = 0; i < pc->sz; i++)
    {
        printf("%-20s%-5d%-5s%-12s%-30s%\n",
            pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
    }
}
void SaveContactsToFile(Contact* pc, const char* filename) {
    assert(pc);
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < pc->sz; i++) {
        fprintf(file, "%s %d %s %s %s\n",
            pc->data[i].name,
            pc->data[i].age,
            pc->data[i].sex,
            pc->data[i].tele,
            pc->data[i].addr);
    }
    fclose(file);
    printf("Contacts saved successfully to %s.\n", filename);
}
void LoadContactsFromFile(Contact* pc, const char* filename) {
    assert(pc);
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    pc->sz = 0;
    while (fscanf(file, "%s %d %s %s %s",
        pc->data[pc->sz].name,
        &pc->data[pc->sz].age,
        pc->data[pc->sz].sex,
        pc->data[pc->sz].tele,
        pc->data[pc->sz].addr) != EOF) {
        pc->sz++;
        if (pc->sz >= MAX) {
            printf("Maximum number of contacts reached.\n");
            break;
        }
    }
    fclose(file);
    printf("Contacts loaded successfully from %s.\n", filename);
}
