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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL || left==right)
            return head;
        ListNode *prev,*curr,*next,*start=head,*end=NULL;
        int cnt = 1;
        while(cnt!=left)
        {
            end=start;
            start = start->next;
            cnt++;
        }
        prev=start;curr=start->next;next=curr->next;
        while(cnt!=right-1)
        {
            curr->next= prev;
            prev=curr;
            curr=next;
            next=curr->next;
            cnt++;
        }
        start->next=curr->next;
        curr->next=prev;
        if(end!=NULL)
        end->next=curr;
        if(end)
            return head;
        return curr;
    }
};