#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void ShellSort(int* arr, int n)//先预排序再插入排序
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap最后会是1,变成插入排序
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end ];
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

int main()
{
	int arr[] = { 6,5,9,8,7,3,4,1,2 };
	int sz = sizeof(arr) / sizeof(int);
	ShellSort(arr, sz);
	for (int i = 0; i < sz; i++)
		cout << arr[i];
	return 0;
}