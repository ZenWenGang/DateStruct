#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stact
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);
//出栈和入栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
//取出栈顶数据
STDataType STTop(ST* pst);
//判空
bool STEmpty(ST* pst);
//获取数据个数
int STsize(ST* pst);