#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
    
};
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    ListNode* l1, * l2;
    l1 = list1;
    l2 = list2;
    ListNode* newhead, * newtail;
    newtail = newhead = NULL;
    //判断链表是否为空
    if (l1 == NULL)
    {
        return list2;
    }
    if (l2 == NULL)
    {
        return list1;
    }

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            if (newhead == NULL)//如果新链表为空
            {
                newhead = newtail = l2;
            }
            else
            {
                newtail->next = l2;
                newtail = newtail->next;
            }
            l2 = l2->next;
        }
        else
        {
            if (newhead == NULL)//新链表为空
            {
                newhead = newtail = l1;
            }
            else
            {
                newtail->next = l1;
                newtail = newtail->next;
            }
            l1 = l1->next;
        }
        //l1/l2其中有一个没遍历完的情况：
        if (l1)
        {
            newtail->next = l1;
        }
        else if (l2)
        {
            newtail->next = l2;
        }
    }
    return newhead;
}