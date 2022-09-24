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
    void solve(TreeNode* root,int t,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            if(t==root->val)
            {
                ds.push_back(root->val);
                ans.push_back(ds);
                ds.pop_back();                
            }
            return;
        }
        ds.push_back(root->val);
        solve(root->left,t-root->val,ds,ans);
        solve(root->right,t-root->val,ds,ans);
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root,t,ds,ans);
        return ans;
    }
};