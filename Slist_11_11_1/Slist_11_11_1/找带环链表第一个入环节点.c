#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode {
    int val;
    struct ListNode* next;
    
};

//依旧快慢指针

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)//如果相遇
        {
            struct ListNode* meet = slow;//记慢指针处节点为相遇节点
            while (meet != head)
            {
                //让头指针跟环内的meet节点一起移动，相遇则为入环的第一个节点
                meet = meet->next;
                head = head->next;
            }
            return meet;
        }

    }
    return NULL;
}