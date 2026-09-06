#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<utility>
using namespace std;

void SelectSort(int* arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int minindex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minindex])
			{
				minindex=j;
			}
		}
		swap(arr[i], arr[minindex]);
	}
}

int main()
{
	int arr[] = { 6,5,9,8,7,3,4,1,2 };
	int sz = sizeof(arr) / sizeof(int);
	SelectSort(arr, sz);
	for (int i = 0; i < sz; i++)
		cout << arr[i];
	return 0;
}