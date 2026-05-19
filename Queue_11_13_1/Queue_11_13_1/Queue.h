#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode//队列头，尾指针跟数据
{
	struct QueueNode* next;
	QDataType val;
}QNode;
typedef struct Queue//包含了队列的头，尾指针跟大小
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
//初始化队列
void QueueInit(Queue* pq);
//尾插
void QueuePush(Queue* pq, QDataType x);
//头删
void QueuePop(Queue* pq);
//大小
int QueueSize(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);
//销毁队列
void QueueDestory(Queue* pq);