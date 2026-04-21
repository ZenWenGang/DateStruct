#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"
#include<assert.h>
//顺序表的初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;//用“->”来解引用
	ps->size = ps->capacity = 0;
}
//顺序表的销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SLCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		//申请空间
		//三目表达式
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;

		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc err!");
			exit(1);
		}
		//空间申请成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//防止传入空指针
	//插入之前检测空间够不够
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
//头插

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//先让顺序表整体内容往后移动一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;//空间增加
}

void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);//顺序表不为空

	--ps->size;
}
//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	//数据整体往前挪动一位
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}