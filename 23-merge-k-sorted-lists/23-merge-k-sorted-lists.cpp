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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto x:lists)
        {
            if(x)
            pq.push({x->val,x});
        }
        ListNode* head = new ListNode(),*ptr;
        ptr = head;
        while(!pq.empty())
        {
            auto node = pq.top().second;
            pq.pop();
            ptr ->next = node;
            if(node->next)
            {
                pq.push({node->next->val,node->next});
            }
            ptr = ptr ->next;
        }
        return head->next;
    }
};