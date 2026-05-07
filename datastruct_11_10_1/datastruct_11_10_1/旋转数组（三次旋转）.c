#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse(int* a, int left, int right)
{

    while (left < right)
    {
        int tmp;
        tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);

}
int main()
{
    int arr[] = { 1,2,3,4,5,6,7 };
    int* p = arr;
    int sz = sizeof(arr)/sizeof(int);
    rotate(p, sz, 3);
    for (int i = 0; i < 7; i++)
    {
      printf("%d", p[i]);
    }
    
	return 0;
}