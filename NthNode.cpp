#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr)
    {

    }
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* fast = dummy;
            ListNode* slow = dummy
        }
}