/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val)
            return lowestCommonAncestor(root,q,p);
        TreeNode* t=root;
        while(t)
        {
            if(t->val >q->val)
                t=t->left;
            else if(t->val <p->val)
                t=t->right;
            else
                return t;
        }
        return t;
    }
};