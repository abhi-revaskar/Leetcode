/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* p,TreeNode* q)
    {
        if(!p)
        {
            if(!q)
                return true;
            return false;
        }
        if(!q)
            return false;
        return p->val==q->val && solve(p->left,q->right) && solve(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        // return solve(root->left,root->right); // RECURSIVE
        stack<TreeNode*> s1,s2;
        if(!root->left != !root->right)
            return false;
        if(!root->left)
            return true;
        if(root->left->val!=root->right->val)
            return false;
        s1.push(root->left);
        s2.push(root->right);
        while(!s1.empty() && !s1.empty())
        {
            TreeNode* t1=s1.top(),*t2=s2.top();
            if(t1->val!=t2->val)
                return false;
            s1.pop();
            s2.pop();
            if(!t1->right != !t2->left || !t1->left != !t2->right)
                return false;
            if(t1->right)
            {
                s1.push(t1->right);
                s2.push(t2->left);
            }
            if(t1->left)
            {
                s1.push(t1->left);
                s2.push(t2->right);
            }
        }
        if(!s1.empty() || !s2.empty())
            return false;
        return true;
    }
};