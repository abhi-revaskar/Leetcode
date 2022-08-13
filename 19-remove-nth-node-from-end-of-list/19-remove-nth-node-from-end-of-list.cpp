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
        ListNode* first,*second;
        first=second=head;
        for (int i = 0; i < n; i++)
        {
          second=second->next;
        }
        if(!second)
        {
          ListNode* temp=head->next;
          delete head;
          return temp;
        }
        while (second->next)
        {
          first=first->next;
          second=second->next;
        }
        ListNode* temp=first->next;
        first->next=first->next->next;
        delete temp;
        return head;
    }
};