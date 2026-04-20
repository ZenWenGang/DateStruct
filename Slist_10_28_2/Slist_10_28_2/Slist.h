#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义节点的结构
//数据+指向下一节点的指针
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//链表的打印
void SLTPrint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);//用二级指针接收

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//尾删
void SLTPopBack(SLTNode** pphead);

//头删
void SLTPopFront(SLTNode** pphead);

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);//不对节点进行操作，只传*phead

//在指定位置之前插?数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);

//在指定位置之后插?数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);

//销毁链表
void SListDesTroy(SLTNode** pphead);



