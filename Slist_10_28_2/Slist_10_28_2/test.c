#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Slist.h"

void SListTest01()
{
	//链表由一个一个的节点组成
	//创建几个节点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data =1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data =2;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data =3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data =4;
	//将四个节点连接起来
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	//调用链表的打印
	SLTNode* plist = node1;//指向头节点
	SLTPrint(plist);
}
void SListTest02()
{
	SLTNode* plist = NULL;//*plist:第一个节点 /一级指针plist
	//测试尾插
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);//&plist:指向第一个节点的指针的地址    /传入一级指针，接收时要用二级指针
	SLTPrint(plist);//指向第一个节点的指针
	SListDesTroy(&plist);
	SLTPrint(plist);
	//测试头插
	/*SLTPushFront(&plist,6);
	SLTPrint(plist);
	SLTPushFront(&plist, 7);
	SLTPrint(plist);
	SLTPushFront(&plist, 8);
	SLTPrint(plist);*/
	//测试尾删
	/*SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);*/
	//测试头删
	/*SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);*/
	//测试查找
	/*SLTNode* find = SLTFind(plist, 1);*/
	//删除pos节点
	/*SLTEraseAfter(find);
	SLTPrint(plist);*/
	/*if (find == NULL)
	{
		printf("没找到!\n");
	}
	else
	{
		printf("找到了！\n");
	}*/
}

int main()
{
	SListTest02();
	return 0;
}