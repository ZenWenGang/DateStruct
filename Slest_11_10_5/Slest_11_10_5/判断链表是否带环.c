#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
//思路：
//用快慢指针
//快指针跟慢指针如果都进环，快指针总会追上慢指针，如果追上就代表这是带环链表
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}