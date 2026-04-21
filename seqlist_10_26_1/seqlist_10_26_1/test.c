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

int main()
{
	SLTest01();
	return 0;
}