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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || !head)
            return head;
        ListNode* temp = head;
        int kk = k;
        while(temp && --kk)
        {
            temp = temp->next;
        }
        if(!temp)
            return head;
        auto prev = reverseKGroup(temp->next,k);
        ListNode* curr=head,*next;
        kk = k;
        while(kk--)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};