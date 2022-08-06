/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* curr = head,*next,*ans;
        while(curr)
        {
            next = curr->next;
            Node* node = new Node(curr->val);
            curr->next = node;
            node->next = next;
            curr = next;
        }
        curr = head,ans = head->next;
        while(curr)
        {
            curr->next->random = (curr->random==NULL)?NULL:curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        while(curr->next->next)
        {
            next = curr->next->next;
            curr->next->next = next->next;
            curr->next = next;
            curr = next;
        }
        curr->next=  NULL;
        return ans;
    }
};