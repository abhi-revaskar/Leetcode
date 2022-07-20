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
    void solve(TreeNode* root,int maxi,int &ans)
    {
        if(!root)
            return;
        if(root->val>=maxi)
            ans++;
        maxi = max(maxi,root->val);
        solve(root->left,maxi,ans);
        solve(root->right,maxi,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root,INT_MIN,ans);
        return ans;
    }
};