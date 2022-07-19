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
    const int mx = 100001,mn = -100001;
public:
    pair<int,int> solve(TreeNode* root,int &ans)
    {
        if(!root)
            return {mx,mn};
        if(!root->left && !root->right)
            return {root->val,root->val};
        auto left = solve(root->left,ans);
        auto right = solve(root->right,ans);
        ans = min(ans,min(root->val-left.second,right.first-root->val));
        return {min(root->val,left.first),max(root->val,right.second)};
    }
    int getMinimumDifference(TreeNode* root) {
       int ans = mx;
        solve(root,ans);
        return ans;
    }
};