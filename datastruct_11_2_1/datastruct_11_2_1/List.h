#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
//创建双向循环链表
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
//初始化链表
void LTInit(LTNode** pphead);
void LTPrint(LTNode* phead);

//在不改变哨兵位的情况下，传一级指针即可
//插入数据之前，链表必须初始化到只有一个头节点的情况
//尾插
void LTPushBack(LTNode* phead,LTDataType x);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//尾删
void LTPTopBack(LTNode* phead);
//头删
void LTPopFront(LTNode* phead);
//查找
LTNode* LTFind(LTNode* phead, LTDataType x);
//在pos位置之后插⼊数据
void LTInsert(LTNode* pos, LTDataType x);
//删除pos节点
void LTErase(LTNode* pos);
//销毁链表
void LTDesTroy(LTNode* phead);
