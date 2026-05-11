#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化和销毁
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//top指向栈顶数据的下一个位置
	pst->top = 0;
	//如果要top指向栈顶数据那就将top初始为-1
	//pst->top=-1;
	pst->capacity = 0;
}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
//出栈和入栈
void STPush(ST* pst,STDataType x)
{
	assert(pst);
	//扩容
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity==0?4:pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc tail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top>0);
	
	pst->top--;
}
//取出栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top>0);
	return pst->a[pst->top-1];
}
//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;//空就是真，0为真
}
//获取数据个数
int STsize(ST* pst)
{
	assert(pst);
	return pst->top;
}
