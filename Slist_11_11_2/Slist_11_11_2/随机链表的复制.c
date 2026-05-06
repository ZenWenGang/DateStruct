#define _CRT_SECURE_NO_WARNINGS 1
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
    
};


struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //先复制链表
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;
        cur->next = copy;

        cur = copy->next;
    }
    //处理random的指向
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    //取到新链表
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}