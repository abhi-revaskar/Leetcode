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
    bool solve(TreeNode* root, int t)
    {
        if(!root->left && !root->right)
        return root->val ==t;
        int val = t - root->val;
        bool ans = false;
        if(root->left)
            ans = ans || solve(root->left,val);
        if(root->right)
            ans = ans || solve(root->right,val);
        return ans;
    }
    bool hasPathSum(TreeNode* root, int t) {
        if(!root)
            return false;
        return solve(root,t);
    }
};