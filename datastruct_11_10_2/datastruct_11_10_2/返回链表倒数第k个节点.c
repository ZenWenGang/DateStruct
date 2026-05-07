#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//用快慢指针，快指针先各k个距离，然后同时走
//快指针先走到空，慢指针所在位置就是倒数第k个
//空间复杂度O(0)
int kthToLast(struct ListNode* head, int k) {
    struct ListNode* fast = head, * slow = head;

    while (k--)//k次
    {
        fast = fast->next;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;
}