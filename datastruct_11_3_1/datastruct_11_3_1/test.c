#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
#include"SList.h"
void menu()
{
	printf("******************     通讯录     ***********************\n");
	printf("*********  1、增加联系人    2、删除联系人  **************\n");
	printf("*********  3、查找联系人    4、修改联系人  **************\n");
	printf("*********  5、展示联系人    6、保存联系人  **************\n");
	printf("*********          0、退出通讯录           **************\n");
}

int main()
{
	int input = -1;
	contact* con = NULL;
	InitContact(&con);

	do
	{
		menu();
		printf("请选择你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(con);
			break;
		case 6:
			SaveContact(con);
			break;
		case 0:
			printf("退出通讯录...\n");
			break;
		default:
			printf("输入错误，请重新选择你的操作:\n");
			break;
		}
	} while (input != 0);

	DestroyContact(&con);
	return 0;
}