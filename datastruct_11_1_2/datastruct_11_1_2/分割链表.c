#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode ListNode;
struct ListNode {
    int val;
    struct ListNode* next;
    
};

typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL)
    {
        return head;
    }
    //创建两个带头链表
    ListNode* lessHead, * lessTail;
    ListNode* greaterHead, * greaterTail;
    lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
    greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));
    //遍历原链表，将节点分别尾插到大小链表中
    ListNode* pcur = head;
    while (pcur)
    {
        if (pcur->val < x)//尾插到小链表中
        {
            lessTail->next = pcur;
            lessTail = lessTail->next;
        }
        else//尾插到大链表中
        {
            greaterTail->next = pcur;
            greaterTail = greaterTail->next;
        }
        pcur = pcur->next;
    }
    greaterTail->next = NULL;//防止只有一个元素的情况出现死循环
    lessTail->next = greaterHead->next;//小链表尾节点跟大链表头节点的下一个节点相连
    ListNode* ret = lessHead->next;
    //释放两个头节点
    free(lessHead);
    free(greaterHead);
    lessHead = greaterHead = NULL;
    lessHead = NULL;
    return ret;
}