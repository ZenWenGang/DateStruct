#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void ListTest01()
{
	LTNode* plist = NULL;
	LTInit(&plist);
	//尾插
	LTPushBack(plist, 1);
	
	LTPushBack(plist, 2);
	
	LTPushBack(plist, 3);
	LTPrint(plist);
	////头插
	//LTPushFront(plist,6);
	//LTPrint(plist);
	//LTPushFront(plist,5);
	//LTPrint(plist);
	//LTPushFront(plist,4);
	//LTPrint(plist);
	//尾删
	/*LTPTopBack(plist);
	LTPrint(plist);*/
	//头删
	/*LTPopFront(plist);
	LTPrint(plist);*/
	//查找
	LTNode* find = LTFind(plist, 1);
	LTInsert(find, 66);
	LTPrint(plist);
	/*if (find == NULL)
	{
		printf("找不到！\n");
	}
	else
	{
		printf("找到了!\n");
	}*/
	LTDesTroy(plist);//因为是一级指针，里面的形参phead被置空，而实参plist没被改变，要手动置空
	plist = NULL;//手动置空
}
int main()
{
	ListTest01();
	return 0;
}