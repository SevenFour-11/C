#define _CRT_SECURE_NO_WARNINGS 1  //禁用vs的安全性警告
#include "game.h"  
void nume()  //菜单显示函数
{
	printf("*******************************\n");
	printf("*****   通讯录管理系统   ******\n");
	printf("***  1.add          2.del  ****\n");//增加和删除指定联系人
	printf("***  3.search       4.modify***\n");//查找和修改指定联系人
	printf("***  5.show         6.sort ****\n");//显示和排序所有联系人
	printf("***  7.empty        0.exit ****\n");//清除所有联系人，和退出程序
	printf("*******************************\n");
}
enum Option  //枚举
{
	EXIT,  //枚举值默认从0开始
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY,
};
int main()
{
	int input = 0;  //存储用户选择
	Contact con;  //存储通讯录数据
	InitContact(&con);  //函数初始化通讯录
	do
	{
		nume();  //nume函数显示菜单
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			PaiContact(&con);
			break;
		case EMPTY:
			QingContact(&con);
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}