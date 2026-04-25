#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//创建节点
typedef struct ListNode ListNode;
//定义链表
struct ListNode {
    int val;
    struct ListNode* next;
};
//创建节点
ListNode* Bydenode(int x)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (node == NULL)
    {
        exit(1);
    }
    node->val = x;
    node->next = NULL;
    return node;
}
//创建带环链表
ListNode* createCircle(int n)
{
    //创建第一个节点
    ListNode* phead = Bydenode(1);
    ListNode* ptail = phead;
    for (int i = 2; i <= n; i++)
    {
        ptail->next = Bydenode(i);
        ptail = ptail->next;
    }
    ptail->next = phead;
    return ptail;
}

int ysf(int n, int m) {
    ListNode* prev = createCircle(n);
    ListNode* pcur = prev->next;
    int count = 1;
    while (pcur->next != pcur)
    {
        if (count == m)
        {
            prev->next = pcur->next;
            free(pcur);
            pcur = prev->next;
            count = 1;
        }
        else
        {
            prev = pcur;
            pcur = pcur->next;
            count++;
        }
    }
    ListNode* ret = pcur->val;
    free(pcur);
    pcur=NULL；
    return ret;
}