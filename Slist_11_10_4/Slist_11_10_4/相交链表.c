#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode {
    int val;
    struct ListNode* next;
    
};
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

//！！！不要判断值，要判断地址是否相等

//思路：排除两个链表都没相交节点的情况
//      记录两个链表长度，假设第二条长，就交换。
//      然后长的先走差距步，走完之后就两个链表同时走并找出相同节点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* curA = headA, * curB = headB;
    int lenA = 0, lenB = 0;
    //先遍历，如果到表尾都没相等的就返回NULL
    while (curA->next)
    {
        curA = curA->next;
        lenA++;
    }
    while (curB->next)
    {
        curB = curB->next;
        lenB++;
    }
    if (curA != curB)
    {
        return NULL;
    }
    //长的先走差距步，再同时走，第一个相等就是交点
    int ret = abs(lenA - lenB);
    struct ListNode* longList = headA, * shortList = headB;
    if (lenB > lenA)
    {
        longList = headB;
        shortList = headA;
    }
    while (ret--)
    {
        longList = longList->next;
    }
    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return shortList;
}