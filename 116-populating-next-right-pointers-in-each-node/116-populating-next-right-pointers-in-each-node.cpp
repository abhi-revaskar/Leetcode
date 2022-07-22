/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* level = root;
        if(!root)
            return root;
        while(level->left)
        {
            Node* it = level;
            while(it)
            {
                it->left->next = it->right;
                if(it->next)
                    it->right->next=it->next->left;
                it=it->next;
            }
            level=level->left;
        }
        return root;
    }
};