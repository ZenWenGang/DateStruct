#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Seqlist.h"
#include"Contact.h"

//void SLTest01()
//{
//	SL sl;
//	SLInit(&sl);//不能传值，只能传地址
//	//增删查改操作
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPrint(sl);
//
//	/*SLPushFront(&sl,5);
//	SLPushFront(&sl,6);
//	SLPrint(sl);*/
//	//测试头删
//	/*SLPopFront(&sl);
//	SLPrint(sl);
//	SLPopFront(&sl);
//	SLPrint(sl);
//	SLPopFront(&sl);
//	SLPrint(sl);
//	SLPopFront(&sl);
//	SLPrint(sl);*/
//
//	//测试尾删
//	SLPopBack(&sl);
//	SLPrint(sl);
//	SLDestroy(&sl);
//}

//void SLTest02()
//{
//	SL sl;
//	SLInit(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPrint(sl);
//	//SLInsert(&sl,0,99);
//	//SLInsert(&sl,sl.size,88);
//	//SLPrint(sl);
//	/*SLErase(&sl, 3);
//	SLPrint(sl);*/
//
//	int find = SLFind(&sl, 3);
//	if (find < 0)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了，下标为%dn\n", find);
//	}
//
//	SLDestroy(&sl);
//}

//通讯录的测试方法
//void ContactTest01()
//{
//	Contact con;//等价于SL  sl
//	Contactinit(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactShow(&con);
//
//	
//	//ContactDel(&con);
//	ContactModify(&con);
//	ContactShow(&con);
//	
//	ContactFind(&con);
//	ContactDestroy(&con);
//}
//int main()
//{
//	//SLTest01();
//	//SLTest02();
//	ContactTest01();
//	return 0;
//}
void menu()
{
	printf("****************通讯录****************\n");
	printf("*******1.增加联系人**2.删除联系人*****\n");
	printf("*******3.修改联系人**4.查找联系人*****\n");
	printf("*******5.展示联系人**0.退出通讯录*****\n");
	printf("**************************************\n");
	
}
int main()
{
	int op = -1;
	Contact con;
	Contactinit(&con);
	do 
	{
		menu();
		printf("请选择您的操作：\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("退出通讯录....................\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;

		}
	} while (op!=0);
	
	ContactDestroy(&con);
	return 0;
}