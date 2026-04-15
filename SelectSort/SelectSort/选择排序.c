#define _CRT_SECURE_NO_WARNINGS 1
//交换
void Swap(int* a, int* b)
{
	int* tmp = *a;
	*a = *b;
	*b = tmp;
}
//选择排序
void SelectSort(int* a, int n)
{
	int bigin = 0, end = n - 1;
	while (bigin < end)
	{
		int max = bigin, min = bigin;
		for (int i = bigin + 1; i <= end; i++)//一共n-2趟（第一个不用自己和自己比）
		{
			//每一趟选出最大和最小，移动下标（不是改i下标，i继续前进）
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		//交换位置
		Swap(&a[min], &a[bigin]);
		if (bigin == max)//重叠的情况
		{
			max = min;
		}
		Swap(&a[max], &a[end]);
		bigin++;
		end--;
	}
}