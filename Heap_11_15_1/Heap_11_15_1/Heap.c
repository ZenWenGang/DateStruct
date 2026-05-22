#define _CRT_SECURE_NO_WARNINGS 
#include"Heap.h"
//初始化堆
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
//销毁堆
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}
//交换数据
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	// 先假设左孩子小
	int child = parent * 2 + 1;

	while (child < n)  // child >= n说明孩子不存在，调整到叶子了
	{
		// 找出小的那个孩子
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//向上调整
void AdjustUP(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;//双亲节点
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);//调换位置
			child =parent ;//关系交换
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//堆的插入
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUP(php->a, php->size - 1);//参数是数组跟数组最后一个元素//  err:php->a[php->size-1]
}
//删除堆顶数据
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
//返回堆顶的数据
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size>0);
	return php->a[0];
}
//判断堆是否为空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}