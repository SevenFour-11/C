#define _CRT_SECURE_NO_WARNINGS 1//����vs�İ�ȫ�Ծ���
#include "game.h"
void InitContact(Contact* pc) //��ʼ��ͨѶ¼
{
	assert(pc);//��ֹ��ָ��
	pc->sz = 0;//��sz��ʼ��Ϊ0
	memset(pc->data, 0, sizeof(pc->data));//���������滻���滻��
}
//������ϵ��
void AddContact(Contact* pc)
{
	assert(pc);//��ֹ��ָ��
	if (pc->sz == MAX)//��ʾͨѶ¼�ṹ��Ŀ��ٵĿռ�����
	{
		printf("ͨѶ¼�������޷�����\n");
		return;
	}
	//ͨѶ¼û����������
	else
	{
		printf("���������֣�");
		scanf("%s", pc->data[pc->sz].name);
		printf("���������䣺");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�������Ա�");
		scanf("%s", pc->data[pc->sz].sex);
		printf("������绰��");
		scanf("%s", pc->data[pc->sz].tele);
		printf("�������ַ��");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;//һ���ṹ�����������󣬾��ڼ��������һ��
		printf("���ӳɹ�\n");
	}
}
//��ӡ������ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);//��ֹ��ָ��
	if (pc->sz == 0)//���sz�Ƿ���ָ��ͷ
	{
		printf("ͨѶ¼Ϊ�գ������ӡ\n");
		return;
	}
	int i = 0;
	printf("%-20s%-5s%-5s%-12s%-30s%\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s%\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}
static int FindByName(Contact* pc, char name[])
{
	assert(pc);//��ֹ��ָ��
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//�Ա������Ƿ���ͬ�������ͬ�ͷ��ظ�ָ���ָ�����ݣ�����ͬ�ͷ���-1
		{
			return i;
		}
	}
	return -1;
}
//ɾ��ָ����ϵ��
void DelContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	if (pc->sz == 0)//��Ҫ��ͨѶ¼�Ƿ�Ϊ��
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵����֣�");
	scanf("%s", name);
	int ret = FindByName(pc, name);//���ز��Һ���
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	int i = 0;
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}
//������ϵ��
void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("������Ҫ�����˵����֣�");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%-20s%-5s%-5s%-12s%-30s%\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s%-5d%-5s%-12s%-30s%\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}
//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("������Ҫ�޸��˵����֣�");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("���������֣�");
	scanf("%s", pc->data[ret].name);
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�");
	scanf("%s", pc->data[ret].sex);
	printf("������绰��");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�\n");
}
//���������ϵ��
void QingContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
	printf("ɾ���ɹ�\n");

}
//����������
int cmp_s(const void* elem1, const void* elem2)
{
	return strcmp((char*)elem1, (char*)elem2);
}
void PaiContact(Contact* pc)
{
	assert(pc);
	qsort(pc, pc->sz, sizeof(pc->data[0]), cmp_s);
	int i = 0;
	printf("%-20s%-5s%-5s%-12s%-30s%\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s%\n",
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}