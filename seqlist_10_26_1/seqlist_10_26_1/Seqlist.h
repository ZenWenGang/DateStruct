#pragma once
#include<stdio.h>
#include<stdlib.h>
//顺序表的结构

//#define N  100


//静态顺序表
//struct Seqlist
//{
//	int arr[N];
//	int size;//有效数据个数
//};

typedef int SLDataType;//方便后期更改类型
//动态顺序表
typedef struct Seqlist
{
	SLDataType* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}SL;

/*typedef struct Seqlist Seqlist;*///定义结构体名

//顺序表初始化
void SLInit(SL* ps);
//顺序表的销毁
void SLDestroy(SL* ps);
//顺序表的打印
void SLPrint(SL s);
//头部插入/尾部插入
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
//头部删除/尾部删除
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);