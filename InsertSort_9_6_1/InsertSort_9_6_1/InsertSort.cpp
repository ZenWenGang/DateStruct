#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])//前一位比后一位大
			{
				arr[end + 1] = arr[end];//元素往后移
				end--;
			}
			else
			{
				break;//找到合适位置
			}
		}
		arr[end + 1] = tmp;//插入到合适位置
	}
}
int main()
{
	int arr[] = { 5,8,7,6,9,3,4,2,1 };
	int sz= sizeof(arr) / sizeof(int);
	InsertSort(arr, sz);
	for (int i = 0; i < sz; i++)
		cout << arr[i];
	return 0;
}