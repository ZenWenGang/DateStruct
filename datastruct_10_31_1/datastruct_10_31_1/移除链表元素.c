#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
   int val;
    struct ListNode* next;
    
};
//创建一个新链表，将值不是val的插入到新链表中，再返回新链表
#include<assert.h>
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
    ListNode* newtail, * newhead,*pval;
    newhead = newtail = NULL;
    pval = head;
    while (pval)
    {
        //尾插
        if (pval->val != val)
        {
            if (newhead == NULL)//新链表为空
            {
                newhead = newtail = pval;
            }
            else
            {
                newtail->next = pval;
                newtail = newtail->next;
            }
        }
        
        pval = pval->next;
    }
    if (newtail)
        newtail->next = NULL;
    return newhead;//返回新的头节点
}