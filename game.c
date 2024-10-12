#define _CRT_SECURE_NO_WARNINGS 1//禁用vs的安全性警告
#include "game.h"
void InitContact(Contact* pc) //初始化通讯录
{
	assert(pc);//防止空指针
	pc->sz = 0;//将sz初始化为0
	memset(pc->data, 0, sizeof(pc->data));//数组名，替换，替换数
}
//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);//防止空指针
	if (pc->sz == MAX)//表示通讯录结构体的开辟的空间满了
	{
		printf("通讯录已满，无法增加\n");
		return;
	}
	//通讯录没有满就输入
	else
	{
		printf("请输入名字：");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄：");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别：");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话：");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址：");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;//一个结构体数据填满后，就在继续填充下一个
		printf("增加成功\n");
	}
}
//打印所有联系人
void ShowContact(Contact* pc)
{
	assert(pc);//防止空指针
	if (pc->sz == 0)//检查sz是否是指向开头
	{
		printf("通讯录为空，无需打印\n");
		return;
	}
	int i = 0;
	printf("%-20s%-5s%-5s%-12s%-30s%\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s%\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}
static int FindByName(Contact* pc, char name[])
{
	assert(pc);//防止空指针
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//对比数据是否相同，如果相同就返回该指针的指向数据，不相同就返回-1
		{
			return i;
		}
	}
	return -1;
}
//删除指定联系人
void DelContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	if (pc->sz == 0)//先要看通讯录是否为空
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("请输入要删除人的名字：");
	scanf("%s", name);
	int ret = FindByName(pc, name);//返回查找函数
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}
//查找联系人
void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要查找人的名字：");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%-20s%-5s%-5s%-12s%-30s%\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s%-5d%-5s%-12s%-30s%\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}
//修改联系人
void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要修改人的名字：");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[ret].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：");
	scanf("%s", pc->data[ret].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功\n");
}
//清空所有联系人
void QingContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
	printf("删除成功\n");

}
//排序所有人
int cmp_s(const void* elem1, const void* elem2)
{
	return strcmp((char*)elem1, (char*)elem2);
}
void PaiContact(Contact* pc)
{
	assert(pc);
	qsort(pc, pc->sz, sizeof(pc->data[0]), cmp_s);
	int i = 0;
	printf("%-20s%-5s%-5s%-12s%-30s%\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s%\n",
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}