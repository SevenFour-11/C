#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h" 
void nume()
{
	printf("*******************************\n");
	printf("    Contact Management System  \n");
	printf("***  1.add          2.del  ****\n");
	printf("***  3.search       4.modify***\n");
	printf("***  5.show         6.sort ****\n");
	printf("***  7.empty        0.exit ****\n");
	printf("***  8.Save Contacts to File **\n");
	printf("***  9.Load Contacts from File \n");
	printf("*******************************\n");
}
enum Option 
{
	EXIT, 
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY,
	SAVE,
	LOAD,
};
int main()
{
	int input = 0; 
	Contact con; 
	const char* filename = "contacts.txt";
	InitContact(&con);
	do
	{
		nume();
		printf("Please enter your choic：");
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
		case SAVE:
			SaveContactsToFile(&con, filename);
			break;
		case LOAD:
			LoadContactsFromFile(&con, filename);
		default:
			break;
		}
	} while (input);
	return 0;
}
