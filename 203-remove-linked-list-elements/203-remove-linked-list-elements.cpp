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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *node = new ListNode(0,head);
        ListNode* it = node;
        while(head)
        {
            if(head->val==val)
            {
                it->next = head->next;
                delete head;
                head = it->next;
            }
            else
            {
                it = it->next;
                head = head->next;
            }
        }
        return node->next;
    }
};