#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//先找中间节点
//再从中间节点开始逆置链表
//最后比较第一个节点跟逆置后的中间节点是否一样
class PalindromeList {
public:
    //逆置链表
     struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* cur=head;
	struct ListNode*newhead = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
//找中间节点
struct ListNode* middleNode(struct ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    bool chkPalindrome(ListNode* A) {
       
       struct ListNode* mid=middleNode(A);//找中间节点
       struct ListNode* rmid=reverseList(mid);//从中间节点开始逆置链表
       while(rmid&&A)
       {
        if(rmid->val!=A->val)//从第一个节点比较中间节点是否一样
        return false;
        rmid=rmid->next;
        A=A->next;
       }
       return true;
    }
};