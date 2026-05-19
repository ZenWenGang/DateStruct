#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
//尾插
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	//将新节点初始化
	newnode->next = NULL;
	newnode->val = x;
	if (pq->ptail == NULL)//队列为空的情况
	{
		pq->phead=pq->ptail = newnode;//这里要注意也要赋给队头
	}
	else
	{
      pq->ptail->next = newnode;
	   pq->ptail= newnode;
	}
	pq->size++;//队列大小增加
}
//头删
void QueuePop(Queue* pq)
{
	assert(pq&&pq->phead);//队列不能为空
	if (pq->phead == pq->ptail)//只有一个节点的情况
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		Queue* next = pq->phead->next;//创一个指针指向phead的下一个节点
		free(pq->phead);
		 pq->phead= next;//这里顺序别弄乱
	}
	pq->size--;//大小减一
}
//取找队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq&&pq->phead);
	return pq->phead->val;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->ptail);
	return pq->ptail->next;
}
//队列大小
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;//size如果等于0就是空
}
//摧毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		Queue* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}