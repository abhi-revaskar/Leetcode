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
    int solve(TreeNode* root,int &ans)
    {
        if(!root)
            return 0;
        int l=solve(root->left,ans)+1;
        int r=solve(root->right,ans)+1;
        ans=max(ans,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans-2;
    }
};