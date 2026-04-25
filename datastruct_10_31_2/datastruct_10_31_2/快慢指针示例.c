#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。

//如果有两个中间结点，则返回第二个中间结点。

//快慢指针法
//思路
//慢指针每次走一步，快指针每次走两步
//快指针为空或快指针的下一个指针为空时，slow指针指向的节点即为中间节点
//注意：循环条件中 fast != NULL 必须放在前面。
typedef struct ListNode ListNode;
struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* middleNode(struct ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
