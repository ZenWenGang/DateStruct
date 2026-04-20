#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"
//链表的打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//申请节点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc err!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
}

//链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x) 
{
	assert(pphead);//不能对空指针解引用//*pphead（第一个节点）可以为空，
	//空链表和非空链表
	SLTNode* newnode=SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
      //找尾
	 SLTNode* ptail = *pphead;
	 while (ptail->next)
	 {
		ptail = ptail->next;
	 }
	  //出循环后ptail指向空
	 ptail->next = newnode;//让ptail指向开好的新节点，完成连接
	}
	
}
//链表头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead&&*pphead);//传入的值不能为空；第一个节点不能为空，即链表不能为空
	//链表只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//链表有多个节点
      SLTNode* ptail = *pphead;
	  SLTNode* prev = *pphead;
	  while (ptail->next)
	  {
		  prev = ptail;
		ptail = ptail->next;
	  }
	  free(ptail);
	  ptail = NULL;
	  prev->next = NULL;
	}
}

//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	SLTNode* next =(*pphead)->next;
	free(*pphead);
	*pphead =next;
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//在指定位置之前插?数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//若pos==*pphead;说明是头插
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
//在指定位置之后插?数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//注意指针关系，先指向pos指向的下一节点，再让pos指向newnode。反过来的话会导致找到不最后一个节点
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	//pos是头节点/pos不是头节点
	if (pos == *pphead)
	{
		//头删
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)//找pos前一个节点
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos&&pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}