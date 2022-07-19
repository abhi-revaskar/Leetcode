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
    bool issame(TreeNode* root,TreeNode* sub)
    {
        if(!root && !sub)
            return true;
        if(!root || !sub)
            return false;
        if(root->val != sub->val)
            return false;
        return issame(root->left,sub->left) && issame(root->right,sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root && sub)
            return false;
        if(issame(root,sub))
            return true;
        return isSubtree(root->left,sub) || isSubtree(root->right,sub);
    }
};