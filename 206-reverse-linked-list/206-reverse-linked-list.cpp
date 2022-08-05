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
    pair<ListNode*,ListNode*> solve(ListNode* head)
    {
        if(head->next==NULL)
            return {head,head};
        auto ans = solve(head->next);
        ans.first->next = head;
        return {head,ans.second};
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        pair<ListNode*,ListNode*> ans;
        ans = solve(head);
        ans.first->next = NULL;
        return ans.second;
    }
};