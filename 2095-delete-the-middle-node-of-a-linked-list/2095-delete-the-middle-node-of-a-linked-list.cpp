/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)
            return NULL;
        ListNode* hh = new ListNode(0,head),*t;
        t = hh;
        while(head && head->next)
        {
            t = t->next;
            head = head->next->next;
        }
        ListNode* todelete = t->next;
        t->next = todelete->next;
        delete todelete;
        return hh->next;
    }
};