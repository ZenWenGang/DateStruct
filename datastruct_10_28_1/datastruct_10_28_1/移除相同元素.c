#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int src;
    int dst;
    src = dst = 0;
    while (src < numsSize)
    {
        if (nums[src] == val)
        {
            src++;
        }
        else
        {
            nums[dst] = nums[src];
            src++;
            dst++;
        }
    }
    return dst;
}
int main()
{
    int arr[] = { 3,2,2,3 };
   int ret=removeElement(arr, 4, 3);
   printf("剩下不同元素：%d个", ret);
	return 0;
}