#define _CRT_SECURE_NO_WARNINGS 1
#include"Stact.h"
//栈的初始化
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;//指向栈顶元素的下一个位置
	pst->capacity = 0;
}
//栈的销毁
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);//直接释放指向数组a的空间
	pst->a = NULL;//指针置空
	pst->top = pst->capacity = 0;
}
//入栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)//空间满的情况要扩容
	{
		STDataType newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;//元素插入数组
	pst->top++;//指针指向下一位
}
//删除数据
void STPop(ST* pst)
{
	assert(pst);
	return pst->top--;//直接指针前移
}
//取出栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);//防止访问空栈
	return pst->a[pst->top - 1];//取指针前一位元素
}
//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;//如果top等于0就代表空栈
}
//获取数据个数
int STsize(ST* pst)
{
	assert(pst);
	return pst->top;
}
