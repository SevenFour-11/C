#define _CRT_SECURE_NO_WARNINGS 1  //����vs�İ�ȫ�Ծ���
#include "game.h"  
void nume()  //�˵���ʾ����
{
	printf("*******************************\n");
	printf("*****   ͨѶ¼����ϵͳ   ******\n");
	printf("***  1.add          2.del  ****\n");//���Ӻ�ɾ��ָ����ϵ��
	printf("***  3.search       4.modify***\n");//���Һ��޸�ָ����ϵ��
	printf("***  5.show         6.sort ****\n");//��ʾ������������ϵ��
	printf("***  7.empty        0.exit ****\n");//���������ϵ�ˣ����˳�����
	printf("*******************************\n");
}
enum Option  //ö��
{
	EXIT,  //ö��ֵĬ�ϴ�0��ʼ
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
	int input = 0;  //�洢�û�ѡ��
	Contact con;  //�洢ͨѶ¼����
	InitContact(&con);  //������ʼ��ͨѶ¼
	do
	{
		nume();  //nume������ʾ�˵�
		printf("���������ѡ��");
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