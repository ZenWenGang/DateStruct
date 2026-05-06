#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//申请节点
LTNode* LTBuynode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc file!");
			exit(1);
	}
	node->data = x;
	node->next = node->prev = node;
}
//初始化链表
void LTInit(LTNode** pphead)
{
	*pphead = LTBuynode(-1);//哨兵位
}
//打印链表
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;//指向哨兵位的下一个节点
	while (pcur != phead)//到哨兵位停止循环
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//尾插
void LTPushBack(LTNode* phead, LTDataType x)//插入数据之前，链表必须初始化到只有一个头节点的情况
{
	assert(phead);
	LTNode* newnode = LTBuynode(x);
	//先动新节点的prev和next的指向
	newnode->prev = phead->prev;
	newnode->next = phead;
	//下面两行代码不能交换位置
	phead->prev->next = newnode;
	phead->prev = newnode;
}
//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuynode(x);
	//先动新节点的prev和next的指向
	newnode->next = phead->next;
	newnode->prev = phead->next->prev;
	//下面两行代码不能交换位置,先动新节点后一个节点的prev的指向，防止找不到该节点
	phead->next->prev = newnode;
	phead->next = newnode;
}
//尾删
void LTPTopBack(LTNode* phead)
{
	assert(phead&&phead->next!=phead);//判空，如果是空链表的话，说明哨兵位指向自己
	LTNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}
//头删
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}
//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//在pos位置之后插⼊数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuynode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
//删除pos节点
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
//销毁链表
void LTDesTroy(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}