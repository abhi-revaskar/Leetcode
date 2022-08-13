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
    void reorderList(ListNode* head) {
        if(!head->next)
            return;
        ListNode* slow = head,*fast = head,*last;
        while(fast && fast->next)
        {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        last ->next = NULL;
        ListNode* prev = NULL,*curr= slow,*next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* h1= head,*h2 = prev,*t1,*t2;
        while(h1 && h2)
        {
            t1 = h1->next;
            t2 = h2->next;
            h1->next = h2;
            if(t1)
            h2->next = t1;
            h1 = t1;
            h2 = t2;
        }
    }
};