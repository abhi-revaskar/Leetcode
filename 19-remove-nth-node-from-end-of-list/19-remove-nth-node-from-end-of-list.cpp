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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hh = new ListNode(0,head),*t1,*t2=head;
        t1 = hh;
        for(int i=0;i<n;i++)
            t2=t2->next;
        while(t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = t1->next->next;
        return hh->next;
        
    }
};