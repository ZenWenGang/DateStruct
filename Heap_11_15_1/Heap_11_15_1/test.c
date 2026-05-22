#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//void HeapTest01()
//{
//	int a[] = { 2,4,8,1,5,9,6,7 };
//	HP hp;
//	HPInit(&hp);
//	for (size_t i = 0; i<sizeof(a) / sizeof(int); i++)
//	{
//		HPPush(&hp,a[i]);
//	}
//	while (!HPEmpty(&hp))
//	{
//		printf("%d ", HPTop(&hp));
//		HPPop(&hp);
//	}
//	HPDestroy(&hp);
//}
void HeapSort(int* a, int n)
{
	//降序用小堆，升序用大堆
	for (int i = 1; i < n; i++)
	{
		AdjustUP(a, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void HeapTest02()
{
	int a[] = { 4,2,8,1,5,6,9,7 };
	HeapSort(a, sizeof(a) / sizeof(int));
}
int main()
{
	HeapTest02();
	return 0;
}