#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ListDataType;
//创建链表
typedef struct ListNode
{
	ListDataType data;
	struct ListNode* next;
}ListNode;
//反转链表
struct ListNode* reverseList(struct ListNode** head)
{
	ListNode* prev = NULL;
	ListNode* pcur = *head;
	while (pcur)
	{
		ListNode* next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	return prev;
}
//打印链表
void PrintLN(ListNode** pphead)
{
	ListNode* pcur = *pphead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL");
}


int main()
{
	//初始化链表
	ListNode* node1 = (ListNode*)malloc(sizeof(ListNode));
	node1->data = 1;
	ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
	node2->data = 2;
	ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
	node3->data = 3;
	ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
	node4->data = 4;
	ListNode* node5 = (ListNode*)malloc(sizeof(ListNode));
	node5->data = 5;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	ListNode* plist = node1;

	reverseList(&plist);
	//PrintLN(&plist);
	return 0;
}