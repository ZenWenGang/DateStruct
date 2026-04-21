#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Seqlist.h"

void SLTest01()
{
	SL sl;
	SLInit(&sl);//不能传值，只能传地址
	//增删查改操作
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);

	/*SLPushFront(&sl,5);
	SLPushFront(&sl,6);
	SLPrint(sl);*/
	//测试头删
	/*SLPopFront(&sl);
	SLPrint(sl);
	SLPopFront(&sl);
	SLPrint(sl);
	SLPopFront(&sl);
	SLPrint(sl);
	SLPopFront(&sl);
	SLPrint(sl);*/

	//测试尾删
	SLPopBack(&sl);
	SLPrint(sl);
	SLDestroy(&sl);
}

void SLTest02()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);
	//SLInsert(&sl,0,99);
	//SLInsert(&sl,sl.size,88);
	//SLPrint(sl);
	/*SLErase(&sl, 3);
	SLPrint(sl);*/

	int find=SLFind(&sl, 3);
	if (find < 0)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了，下标为%dn\n", find);
	}

	SLDestroy(&sl);
}
int main()
{
	SLTest01();
	//SLTest02();
	return 0;
}