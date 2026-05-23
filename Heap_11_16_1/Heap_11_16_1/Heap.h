#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//初始化堆
void HPInit(HP* php);
//堆的销毁
void HPDestroy(HP* php);
//堆的插入
void HPPush(HP* php, HPDataType x);
//删除堆顶数据
void HPPop(HP* php);
//返回堆顶的数据
HPDataType HPTop(HP* php);
//堆的判空
bool HPEmpty(HP* php);
//向下调整算法
void AdjustDown(HPDataType* a, int n, int parent);
//向上调整算法
void AdjustUP(HPDataType* a, int child);
//交换位置
void Swap(HPDataType* q1, HPDataType* q2);
